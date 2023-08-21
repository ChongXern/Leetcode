class Solution:
    def countTime(self, time: str) -> int:
        counter = 1
        if time[3] == '?':
            counter *= 6
        if time[4] == '?':
            counter *= 10
        if time[0] == '?' and time[1] == '?':
            counter *= 24
        elif time[0] == '?':
            if time[1] >= '0' and time[1] < '4':
                counter *= 3
            else:
                counter *= 2
        elif time[1] == '?':
            if time[0] == '2':
                counter *= 4
            else:
                counter *= 10
        return counter

solution = Solution()

time = input("Input time: ")
timeCount = solution.countTime(time)

print("Number of valid clock times: ", timeCount)
