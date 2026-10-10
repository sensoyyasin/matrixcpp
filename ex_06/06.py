import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "include"))

from Vector import Vector, cross_product
from Matrix import Matrix


def main():
    u = Vector([0., 0., 1.])
    v = Vector([1., 0., 0.])
    print(cross_product(u, v)) # [0.] [1.] [0.]

    u = Vector([1., 2., 3.])
    v = Vector([4., 5., 6.])
    print(cross_product(u, v)) # [-3.] [6.] [-3.]

    u = Vector([4., 2., -3.])
    v = Vector([-2., -5., 16.])
    print(cross_product(u, v)) # [17.] [-58.] [-16.]



if __name__ == "__main__":
    main()
