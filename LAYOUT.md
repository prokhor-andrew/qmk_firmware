# Moonlander Keyboard Layout

## Layer Overview

| # | Name | Access |
|---|------|--------|
| 0 | Text | Default |
| 1 | Symbols | `OSL(1)` outer column key (row 1, both sides) |

---

## Layer 0 — Text (QWERTY)

```
LEFT                                          RIGHT
 —     —      —     ⌘L      —      —      —    —     —      —     ⌘R      —      —      —
^OSM   Q      W      E      R      T     [     ]     Y      U      I      O      P    ⌥OSM
ESC    A      S      D      F      G     `     '     H      J      K      L      ;   HYPR
⇧OSM   Z      X      C      V      B           N     M      ,      .      /    ⇧OSM
 —     —      —     BSP   SPC     —           —    ENT    TAB     —      —      —
OSL(1)  —      —                         —      —    OSL(1)
```

- `OSL(1)` = One-shot Symbols layer (tap once, next key is from Symbols)
- `⇧OSM` = One-shot Shift
- `⌘L` = One-shot Left Cmd
- `⌘R` = One-shot Right Cmd
- `^OSM` = One-shot Ctrl

---

## Layer 1 — Symbols (one-shot from OSL(1))

```
LEFT                                          RIGHT
 —     —      —     ⌘L      —      —      —    —     —     ⌘R      —      —      —      —
^OSM   0      1      2      3      4      —    —     =      {      }      \      $    ⌥OSM
ESC    5      6      7      8      9      —    —     -      (      )      ^      %   HYPR
⇧OSM   #      &      +      *      !           _     [      ]      |      @    ⇧OSM
 —     —      —     BSP   SPC     —           —    ENT    TAB     —      —      —
```

> **Note:** Shift+number on left produces the bare number (not the shifted symbol) — handled in `process_record_user`.

---

## Key Notation

| Symbol | Meaning |
|--------|---------|
| `OSL(n)` | One-shot layer n (next key comes from layer n, then returns) |
| `OSM(mod)` | One-shot modifier |
