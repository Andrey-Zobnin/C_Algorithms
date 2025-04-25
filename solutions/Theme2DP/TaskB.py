def main():

    import sys

    input = sys.stdin.read

    data = input().splitlines()

    

    t = 1 

    index = 0

    

    while t > 0:

        t -= 1

        n = int(data[index])

        index += 1

        a = list(map(int, data[index].split()))

        index += 1

        

        a.sort()

        dp = [[float('inf')] * n for _ in range(n)]

        

        for i in range(n):

            dp[i][i] = 0

        

        for d in range(n):

            for i in range(n - d):

                j = i + d

                if i != 0:

                    dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + (a[j] - a[i - 1]))

                if j != n - 1:

                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (a[j + 1] - a[i]))

        

        print(dp[0][n - 1])


if __name__ == "__main__":

    main()