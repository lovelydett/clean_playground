import { Vector } from "./vector"; // Vector is an exported class, not an exported type

let vec1: Vector = new Vector(1, 2);
let vec2: Vector = new Vector(3, 4);

let vec3: Vector = vec1.add(vec2);

console.log(vec3.x, vec3.y);