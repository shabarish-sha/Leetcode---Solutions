class Solution(object):
    def maxPoints(self, points):
        if len(points) <= 2:
            return len(points)

        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        result = 0

        for i in range(len(points)):
            slopes = {}
            same = 1
            vertical = 0

            for j in range(i + 1, len(points)):
                if points[i] == points[j]:
                    same += 1
                elif points[i][0] == points[j][0]:
                    vertical += 1
                else:
                    dx = points[j][0] - points[i][0]
                    dy = points[j][1] - points[i][1]
                    g = gcd(dx, dy)
                    dx //= g
                    dy //= g
                    slopes[(dx, dy)] = slopes.get((dx, dy), 0) + 1

            curr_max = vertical
            for count in slopes.values():
                curr_max = max(curr_max, count)

            result = max(result, curr_max + same)

        return result