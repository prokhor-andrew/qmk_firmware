# Moonlander Keyboard Layout

## Layer Overview

| # | Name | Access |
|---|------|--------|
| 0 | Nav | Default / `TO(0)` left thumb |
| 1 | Text | `TO(1)` right thumb |
| 2 | Symbols | Hold `ESC` or `TAB` in Text layer |
| 3 | Apps | Hold `A` in Nav layer |
| 4 | Windows | Hold `S` in Nav layer |
| 5 | Tabs | Hold `D` in Nav layer |
| 6 | Scroll | Hold `F` in Nav layer |
| 7 | Arrows | Hold `G` in Nav layer |
| 8 | Controls | `TO(8)` left-center thumb |
| 9 | Mouse | `TO(9)` right-center thumb |
| 10 | Mouse-Move | Hold `F` in Mouse layer |
| 11 | Neru-Nav | Hold `D` in Mouse layer |

---

## Thumb Clusters (all layers)

```
[ Nav  ] [ Ctrl ] [  —  ]       [  —  ] [ Mouse] [ Text ]
  TO(0)    TO(8)                          TO(9)    TO(1)
```

---

## Layer 0 — Nav (Home)

Left side: app launchers (row 2) + scope-layer selectors (row 3). Right side: a few Hyper shortcuts.

```
LEFT                                          RIGHT
 —     —      —      —      —      —      —    —     —      —      —      —      —      —
 —   H(Q)   H(T)   H(G)   H(I)    —      —    —     —    H(B)   H(N)   H(S)   H(F)    —
 —  [Apps] [Win]  [Tabs] [Scrl] [Arr]    —    —     —      —      —      —      —      —
     MO(3) MO(4)  MO(5)  MO(6)  MO(7)
 —     —      —      —      —      —           —     —      —      —      —      —
 —     —      —      —      —    H(P)        H(-) —      —      —      —      —
```

`H(x)` = Hyper (Ctrl+Alt+Shift+Cmd) + x — used to trigger app launcher shortcuts.

---

## Layer 1 — Text (QWERTY)

```
LEFT                                          RIGHT
 —     —      —      —      —      —      —    —     —      —      —      —      —      —
 —     Q      W      E      R      T     [     ]     Y      U      I      O      P      —
ESC²   A      S      D      F      G     `     '     H      J      K      L      ;    TAB²
⇧OSM   Z      X      C      V      B           N     M      ,      .      /    ⇧OSM
 —     —      —     BSP   SPC      —           —    ENT   ⌘OSM    —      —      —
```

- `ESC²` / `TAB²` = Tap → Escape / Tab; Hold → Layer 2 (Symbols)
- `⇧OSM` = One-shot Shift
- `⌘OSM` = One-shot Cmd

---

## Layer 2 — Symbols (hold ESC or TAB in Text)

```
LEFT                                          RIGHT
 —     —      —      —      —      —      —    —     —      —      —      —      —      —
 —     0      1      2      3      4      —    —     =      {      }      \      $      —
 —     5      6      7      8      9      —    —     -      (      )      ^      %      —
 —     #      &      +      *      !           _     [      ]      |      @      —
 —     —      —     BSP   SPC      —           —    ENT   ⌘OSM    —      —      —
```

> **Note:** Shift+number on left produces the bare number (not the shifted symbol) — handled in `process_record_user`.

---

## Scope Layers (3–7)

All accessed by holding a key on the home row of Layer 0. Each layer only activates the **right home row** (H/J/K/L); everything else is transparent.

### Layer 3 — Apps (hold `A`)

| H | J | K | L |
|---|---|---|---|
| Hyper+H | Hyper+J | Hyper+K | Hyper+L |
| prev-app | — | mission control | next-app |

### Layer 4 — Windows (hold `S`)

| H | J | K | L |
|---|---|---|---|
| Meh+H | Meh+J | Meh+K | Meh+L |
| prev-win | close-win | new-win | next-win |

### Layer 5 — Tabs (hold `D`)

| H | J | K | L |
|---|---|---|---|
| LCA+H | LCA+J | LCA+K | LCA+L |
| prev-tab | close-tab | new-tab | next-tab |

### Layer 6 — Scroll (hold `F`)

| H | J | K | L |
|---|---|---|---|
| Wheel ← | Wheel ↓ | Wheel ↑ | Wheel → |

### Layer 7 — Arrows (hold `G`)

| H | J | K | L |
|---|---|---|---|
| ← | ↓ | ↑ | → |

---

## Layer 8 — Controls (Ctrl thumb)

Only right home row active. Same thumb cluster as Layer 0.

| H | J | K | L |
|---|---|---|---|
| Vol ↓ | Brightness ↓ | Brightness ↑ | Vol ↑ |

---

## Layer 9 — Mouse (Mouse thumb)

```
LEFT home row:
  D = NERU_D   →  tap: toggle Neru grid (Cmd+Shift+C); hold: activate Neru-Nav (layer 11)
  F = MO(10)   →  hold: activate Mouse-Move layer

Thumb row:
  Space-position = BTN1 (left click)
  Enter-position = BTN2 (right click)
```

---

## Layer 10 — Mouse-Move (hold `F` in Mouse)

Cursor movement on right home row:

| H | J | K | L |
|---|---|---|---|
| Mouse ← | Mouse ↓ | Mouse ↑ | Mouse → |

---

## Layer 11 — Neru-Nav (hold `D` in Mouse)

Activated while `D` is held after opening the Neru grid. Maps to Neru grid quadrants:

```
      U    I
      J    K
```

| Key | Neru Corner |
|-----|-------------|
| U | Top-left |
| I | Top-right |
| J | Bottom-left |
| K | Bottom-right |

On `D` release: layer 11 turns off and `Escape` is sent to Neru.

---

## Key Notation

| Symbol | Meaning |
|--------|---------|
| `H(x)` | Hyper (Ctrl+Alt+Shift+Cmd) + x |
| `Meh(x)` | Meh (Ctrl+Alt+Shift) + x |
| `LCA(x)` | Left Ctrl+Alt + x |
| `OSM(mod)` | One-shot modifier |
| `MO(n)` | Momentary layer n (active while held) |
| `TO(n)` | Switch to layer n (stays until changed) |
| `LT(n,k)` | Tap = key k; Hold = layer n |
