/***
 * @fileoverview IIFE stands for Immediately Invoked Function Expression.
 */

"use strict";

// IIFE is a function that is executed right after it is defined.
// In such, this code snippet is guaranteed that:
// - 1. it only gets executed once and immediately at this place.
// - 2. all the variables it uses are concealed within the scope of the function.
// Its major use is to preserve a private scope within your function.

// Example 1
console.log("Example 1:");
(function () {
  let x = 1;
  let y = 2;
  console.log(x + y);
})();

// Example 2: simulating a static variable
console.log("Example 2:");
let counter = (function () {
  let counter = 1;
  return () => {
    counter++;
    return counter;
  };
})();

console.log(counter());
console.log(counter());
console.log(counter());

// Example 3: simulating private variable
console.log("Example 3:");
const myCounter = (function () {
  // prv is not accessible upon completion of the IIFE
  let prv = "This is a private string that should not be directly accessed";

  return {
    getPrv: () => {
      return prv;
    },
    setPrv: (_prv) => {
      prv = _prv;
    },
  };
})();

console.log(myCounter.getPrv());
myCounter.setPrv("This is a new private string");
console.log(myCounter.getPrv());
