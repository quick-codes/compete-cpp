## Compete-C++

Contains quick snippets in c++

#### Sample Inputs

###### Vector as input

```c++
int main() {
  const static Integer null(INT32_MIN);
  const vector<vector<int>> inputs = {
	  {30, 20, 150, 100, 40},
	  {60, 60, 60},
  };

  Solution solution = Solution();
  for (auto input : inputs) {
	cout << "Input: time = " << input << endl;
	cout << "Output: " << solution.numPairsDivisibleBy60(input) << endl;
  }
  return 0;
}
```
