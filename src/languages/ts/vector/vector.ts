class Vector {
  x: number;
  y: number;
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
  add(vector: Vector): Vector {
    let vec: Vector = new Vector(0, 0);
    vec.x = this.x + vector.x;
    vec.y = this.y + vector.y;
    return vec;
  }
  sub(vector: Vector) {
    this.x -= vector.x;
    this.y -= vector.y;
  }
  mult(n: number) {
    this.x *= n;
    this.y *= n;
  }
  div(n: number) {
    this.x /= n;
    this.y /= n;
  }
  mag() {
    return Math.sqrt(this.x * this.x + this.y * this.y);
  }
}

export { Vector };