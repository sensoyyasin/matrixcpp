from Matrix import Matrix

class Vector:
    def __init__(self, data_list):
        self.data = []
        for element in data_list:
            self.data.append(float(element))


    def add(self, v):
        for i in range(len(self.data)):
            self.data[i] += v.data[i]

    def sub(self, v):
        for i in range(len(self.data)):
            self.data[i] -= v.data[i]

    def scl(self, a):
        for i in range(len(self.data)):
            self.data[i] *= a

    def __str__(self):
        lines = []
        for element in self.data:
            lines.append("[" + str(element) + "]")
        return "\n".join(lines)

    def size(self):
        return len(self.data)


    def dot(self, v):
        #u = Vector([-1., 6.])
        #v = Vector([3., 2.])
        #print("{}", u.dot(v)) #9.0
        if self.size() != v.size():
            return "Dot product should be the same dimension"

        dot = 0
        for i in range(len(self.data)):
            dot += self.data[i] * v.data[i]
        return dot


def linear_combination(vector_list, coefs):
    size = len(vector_list[0].data)

    res = []
    for j in range(size):
        res.append(0.0)

    for i in range(len(vector_list)):
        for j in range(size):
            res[j] += vector_list[i].data[j] * coefs[i]

    return Vector(res)

#fn lerp::<V>(u: V, v: V, t: f32) -> V;
# u + t * (v - u)
def lerp(u, v, t):
    # Number
    if isinstance(u, (int, float)):
        return u + t * (v - u)

	# Vector
    if isinstance(u, Vector):
        res = []
        for i in range(len(u.data)):
            res.append(u.data[i] + t * (v.data[i] - u.data[i]))
        return Vector(res)

	# Matrix
    if isinstance(u, Matrix):
        res = []
        for i in range(u.rows):
            lst = []
            for j in range(u.cols):
                lst.append(u.data[i][j] + t * (v.data[i][j] - u.data[i][j]))
            res.append(lst)


        return Matrix(res)
