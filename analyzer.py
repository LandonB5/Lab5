import time
import stringdata
#1
def linear_search(words, word):
    for i, value in enumerate(words):
        if value == word:
            return i
    return -1
#123
def binary_search(words, word):
    #looked up binary search to make sure my logic was right based on my initial time numbers
    low = 0
    high=len(words) - 1
    while low <= high:
        mid = (low + high) // 2
        if words[mid] == word:
            return mid
        elif words[mid] < word:
            low = mid + 1
        else:
            high = mid - 1
    return -1


def main():
    dataset = stringdata.get_data()
    things = ["not_here", "mzzzz", "aaaaa"]
    for element in things:
        start_time = time.time()
        result = linear_search(dataset, element)
        end_time = time.time()
        print(f"Linear search for {element}: Index={result}, Time={end_time - start_time:.10f} seconds")
        start_time = time.time()
        result = binary_search(dataset, element)
        end_time = time.time()
        print(f"Binary search for {element}: Index={result}, Time={end_time - start_time:.10f} seconds")
if __name__ == "__main__":
    main()