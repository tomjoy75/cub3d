"""Decode the .xpm textures into the raw form the browser build loads.

Writes rgba/<name>.rgba: int32 width, int32 height, then B,G,R,X bytes —
MiniLibX's own layout, so cb_draw_pix_color_get reads it with no conversion.
Downscales to 256px on the long edge, which is the most any wall column can
resolve; sign2.xpm goes 11.8 MB -> 9 KB with nothing visibly lost.

SPIKE FORM. This embeds the raw buffers into the .wasm, which is the 26 MB
path. Shipping decodes PNG/WebP in the browser and copies into the heap
instead - ticket 06. Kept because it is what proved the decode is correct.

    python3 wasm/textures.py && sh wasm/build.sh
"""
import glob, os, re, struct, sys, zlib

CAP = 256

def read_xpm(path):
    rows = re.findall(r'"((?:[^"\\]|\\.)*)"', open(path, errors='replace').read(), re.S)
    w, h, nc, cpp = (int(x) for x in rows[0].split()[:4])
    pal = {}
    for row in rows[1:1 + nc]:
        m = re.search(r'\bc\s+(#[0-9A-Fa-f]{6,12}|\S+)', row[cpp:])
        v = m.group(1) if m else '#000000'
        if v.startswith('#'):
            d = v[1:]; n = len(d) // 3
            pal[row[:cpp]] = tuple(int(d[i*n:(i+1)*n][:2], 16) for i in range(3))
        else:
            pal[row[:cpp]] = (0, 0, 0)
    pix = [[pal.get(r[x*cpp:(x+1)*cpp], (0, 0, 0)) for x in range(w)]
           for r in rows[1 + nc:1 + nc + h]]
    return w, h, pix

def downscale(w, h, pix, cap):
    if max(w, h) <= cap:
        return w, h, pix
    s = cap / max(w, h)
    nw, nh = max(1, int(w * s)), max(1, int(h * s))
    return nw, nh, [[pix[int(y*h/nh)][int(x*w/nw)] for x in range(nw)] for y in range(nh)]

os.makedirs('rgba', exist_ok=True)
total = 0
for f in sorted(glob.glob('data/*.xpm')):
    w, h, pix = read_xpm(f)
    w, h, pix = downscale(w, h, pix, CAP)
    buf = bytearray()
    for row in pix:
        for r, g, b in row:
            buf += bytes((b, g, r, 0))
    out = 'rgba/' + os.path.basename(f)[:-4] + '.rgba'
    open(out, 'wb').write(struct.pack('<ii', w, h) + bytes(buf))
    total += os.path.getsize(out)
    # A decode that silently lost its palette makes every texture tiny and the
    # budget fiction, so assert the colours survived.
    seen = len({p for row in pix for p in row})
    if seen < 2:
        sys.exit(f'{f}: decoded {seen} colours - palette parse failed')
print(f'{len(glob.glob("rgba/*.rgba"))} textures, {total // 1024} KB raw')
