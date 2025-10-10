### Important points

- Beware of 192. addresses
- Left-side network doesn't need an entry in router's routing table
- R2, R21 and R12 seem fine as-is but aren't
- cation (bottom right) can be on a 5.5.5.0/30
- In proton/R1 (center router) table add default -> R2 (router below) so meson can talk to gluon
