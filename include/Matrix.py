class Matrix:
    def __init__(self, rows_list):
        self.data = []
        for row in rows_list:
            new_row = []
            for element in row:
                new_row.append(float(element))
            self.data.append(new_row)

        self.rows = len(self.data)
        self.cols = len(self.data[0])


    def add(self, v):
        for i in range(self.rows):
            for j in range(self.cols):
                self.data[i][j] += v.data[i][j]

    def sub(self, v):
        for i in range(self.rows):
            for j in range(self.cols):
                self.data[i][j] -= v.data[i][j]

    def scl(self, a):
        for i in range(self.rows):
            for j in range(self.cols):
                self.data[i][j] *= a

    def __str__(self):
        lines = []
        for row in self.data:
            parts = []
            for element in row:
                parts.append(str(element))
            lines.append("[" + ", ".join(parts) + "]")
        return "\n".join(lines)

	# impl<K> Matrix::<K> {
	#fn mul_vec::<K>(&mut self, vec: Vector::<K>) -> Vector::<K>;
	#fn mul_mat::<K>(&mut self, mat: Matrix::<K>) -> Matrix::<K>;
	#}
    def mul_vec(self, v):
        from Vector import Vector
        res = []
        for i in range(self.rows):
            total = 0.0
            for j in range(self.cols):
                total += self.data[i][j] * v.data[j]
            res.append(total)

        return Vector(res)

    def mul_mat(self, m):
        res = []
        for i in range(self.rows):
            new_row = []
            for j in range(m.cols):
                total = 0.0
                for k in range(self.cols):
                    total += self.data[i][k] * m.data[k][j]
                new_row.append(total)
            res.append(new_row)
        return Matrix(res)

    def trace(self):
        if self.rows != self.cols:
            return "Trace is only defined for square matrices"

        total = 0
        for i in range(self.rows):
            total += self.data[i][i]

        return total

    def transpose(self):
        res = []
        for j in range(self.cols):
            new_row = []
            for i in range(self.rows):
                new_row.append(self.data[i][j])
            res.append(new_row)

        return Matrix(res)
