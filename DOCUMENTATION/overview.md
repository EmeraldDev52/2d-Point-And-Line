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
Polygon is a polygon which is created by giving it 
int sides, double innerCircleRadius = 1, Vector2d origin = Vector2d::ZERO, Vector2d scale = Vector2d::ONE, double rotationOffset = 0

 1. an amount of sides(int)
 2. a radius of inner circle(double) (optional, default = 1)
 3. an origin(Vector2d) (optional, default = Vector2d::ZERO)
 4. a scale(Vector2d) (optional, default = Vector2d::ONE) (a Vector2d that stretches the polygon)
 5. a rotation offset(double) (optional, default = 0) (rotates the polygon clockwise (degrees)) 

 by default, it is a regular polygon but you can set the points manually

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
