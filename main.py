import numpy as np
import matplotlib.pyplot as plt

if __main__
# Create an array of 10 random numbers between 1 and 10
arr = np.random.randint(1, 11, size=10)

# Display a histogram of the array distribution
plt.hist(arr, bins=10, range=(1, 10))
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('Distribution of Array')
plt.show()