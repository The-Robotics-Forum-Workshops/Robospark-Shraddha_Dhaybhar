import heapq

def mincost(arr,n):
    heapq.heapify(arr)

    result=0

    while(len(arr)>1):
        first=heapq.heappop(arr)
        second=heapq.heappop(arr)

        result=result+(first+second)
        heapq.heappush(arr,first+second)

    return result


lengths=[int(x) for x in input("Enter the lengths of ropes:").split()]
size=len(lengths)

print("Total cost for connecting ropes is " + str(mincost(lengths,size)))
