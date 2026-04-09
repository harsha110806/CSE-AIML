def sum_of_subsets(arr, target, index, current):
    
    # If target is achieved
    if target == 0:
        print(current)
        return
    
    # If out of bounds or target negative
    if index >= len(arr) or target < 0:
        return
    
    # Include current element
    current.append(arr[index])
    sum_of_subsets(arr, target - arr[index], index + 1, current)
    
    # Backtrack (remove element)
    current.pop()
    
    # Exclude current element
    sum_of_subsets(arr, target, index + 1, current)


# Input
arr = [1,2,5,6,8]
target = 9

# Call function
sum_of_subsets(arr, target, 0, [])