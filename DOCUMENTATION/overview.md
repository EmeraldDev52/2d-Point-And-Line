# Geo2d

## Main Classes

 1. Vector2d
 2. Line2d
 3. Polygon
 4. BoundingBox
 ---
 
 ### Vector2d
 ---
 
 Vector2d is.. well, a 2d vector defined by x and y coords and has various helpful functions you may need when working with vectors
 
 ---
 ### Line2d
---
 
 Line2d is a 2d line *segment* defined by 2 Vector2d's and has various function like `intersects()`, `length()`, etc

---
### Polygon
---
Polygon is a regular polygon which is created by giving it

 1. an amount of sides(int)
 2. an apothem(radius of inner circle)(double)
 3. an origin(Vector2d)

 and has various helpful functions like
 `overlaps()` which returns whether 2 polygons overlap,
 `contains()` which returns whether the polygon contains a specified point(Vector2d),
 `getBoundingBox()` which returns the BoundingBox of the polygon,
 etc
 
 ---
### BoundingBox
---
BoundingBox is defined by 2 Vector2d's (topLeft, bottomRight) and has functions like
`intersects()` which returns whether 2 BoundingBoxes overlap

---
