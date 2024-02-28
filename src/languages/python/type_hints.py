'''Explore the type hints feature of python and the typing module, see PEP-484 for more details.'''

from typing import List, Tuple, Dict, Any, Union, Optional, TypeVar, Generic, Callable

MyTuple = Tuple[int, str, float]


def accepts_tuple(t: Tuple[int, str, float]) -> None:
    print(accepts_tuple.__annotations__)


t = (1, 'hello', 3.14)
accepts_tuple(t)


MyVector = Tuple[float, float, float]

vec = (1.0, 2.0, 3.0)


def accepts_vector(v: MyVector) -> None:
    print(accepts_vector.__annotations__)


# Union
def square_root(x: Union[int, float]) -> float:
    '''x can be either an int or a float, and the return type is a float.'''
    return x ** 0.5

# Callable


def call_it(f: Callable[[int, int], int], a: int, b: int) -> int:
    return f(a, b)

# Partial callables


def partial_call(f: Callable[[int, int], int], a: int) -> Callable[[int], int]:
    return lambda b: f(a, b)
