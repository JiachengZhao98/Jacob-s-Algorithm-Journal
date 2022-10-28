         /*
                           _ooOoo_
                          o8888888o
                          88" . "88
                          (| -_- |)
                          O\  =  /O
                       ____/`---'\____
                     .'  \\|     |//  `.
                    /  \\|||  :  |||//  \
                   /  _||||| -:- |||||-  \
                   |   | \\\  -  /// |   |
                   | \_|  ''\---/''  |   |
                   \  .-\__  `-`  ___/-. /
                 ___`. .'  /--.--\  `. . __
              ."" '<  `.___\_<|>_/___.'  >'"".
             | | :  `- \`.;`\ _ /`;.`/ - ` : | |
             \  \ `-.   \_ __\ /__ _/   .-` /  /
        ======`-.____`-.___\_____/___.-`____.-'======
                           `=---='
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                 Buddha bless         NO BUG
        */
  
# Some of my answers and thoughts when solving LeetCode and other interview problems.

- Suggestions of improvement are strongly welcomed.

- Including some problems from Amazon Online Assessment and Virtual Onsite Interview

---

# Programming language tips from learning how to solve leetcode problems

## Content

+ [CPP](#CPP)
+ [Java](#Java)
+ [Python](#Python)


---

### CPP <a name="CPP"></a>

+ [vector](#vector)
+ [deque](#deque)
+ [priority_queue](#priority_queue)
+ [string](#string)

#### ```vector```<a name="vector"></a>:
+ The usage of a 2-D ```vector``` ➡️ [click here](https://www.digitalocean.com/community/tutorials/2d-vectors-in-c-plus-plus) 

+ About built-in sorting function for ```vector```:```vector.sort()```:
	- The C++ standard specifies that the worst-case runtime of std::sort() is in O(n log n)
	-  the usage for the third argument:
		- ``` bool myfunction (int i,int j) { return (i<j); } //acending ```
		- ```bool myfunction2 (int i,int j) { return (i>j); }  //desending ```
		- ```static bool cmp(int a, int b) {return abs(a) > abs(b); // desending based on absolute values} ```


+ pay more attention to the value of **i** when using the *for* loop, 'cause when one loop is down **i** will ++


+ how to get the number of rows and columns from a 2-D ```vector```:
	+ ```int size_row = vec.size();  //acquire the number of row ```
	+ ``` int size_col = vec[0].size();  //acquire the number of column```
	
+ how to round the output into two digits ( just remembering the code below is enough...):

``` 
#include<iomanip>  //header file
cout<<setiosflags(ios::fixed)<<setprecision(2);
```

+ ``` vector::resize(int n, int val)```
The function alters the container’s content in actual by inserting or deleting the elements from it. It happens so,
If the given value of n is less than the size at present then extra elements(at the END of the ```vector```) are demolished.
If n is more than current size of container then upcoming elements are appended at the end of the vector.

+ ```vector``` Initialization: 

```
vector<int> ilist1; // first 
vector<int> ilist2(ilist1);  // second 
vector<int> ilist3  = ilist1; // third 
// ilist1, ilist2 and ilist3 are all the SAME !!!

vector<int> ilist = {1,2,3.0,4,5,6,7};
vector<int> ilist {1,2,3.0,4,5,6,7};
// If met some values that are not int, this func will automatically change the value type. 

 vector<int> ilist3(ilist.begin()+2,ilist.end()-1); //e.g. ilist3 = {3, 4, 5, 6} 
// the vector only copies to the front value of the second value input

 vector<int> ilist4(7); // this vector will contain 7 values, which are not initialized. 

 vector<int> ilist5(7,3); // there are seven integers in this vector, which values are all 3. 
 
 vector<vector<vector<int>>> dp = vector(k, vector(m, vector(n, -1))); 
 // initialize a 2-D vector with m rows, n columns and the default value of -1
```

+ How to delete elements within a ```vector```:

```
vector::erase()
iterator erase ( iterator position ); //delete the value in the certain position

iterator erase ( iterator first, iterator last ); // delete a certain sequence of elements within a vector

vector::pop_back()
   void pop_back ( ); // delete the last element in a vector. NO return values
```

+ How to copy a ```vector``` to another ```vector```: ```a = b;```, Where ```a``` and ```b``` are ```vector```.

+ We can NOT use ```new``` to create a ```vector```.

+ The difference between ```vector<vector<int>> vec``` and ```vector<int> F[N]```: 
In the first case we are creating a dynamic array of dynamic arrays (vector of vectors). The size of each vector could be changed at the run-time and all objects will be allocated on the heap.
In the second case we are creating a fixed-size array of vectors. You have to define N at compile-time, and all vectors will be placed on the stack, however, each vector will allocate elements on the heap.


#### ```deque```<a name="deque"></a>:

➡️ [check here](https://blog.csdn.net/sevenjoin/article/details/88530962) 

#### ```priority_queue```<a name="priority_queue"></a>:
➡️ [check here](https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/)

+ two examples:

```
priority_queue<int> pq; // High to low

priority_queue<int, vector<int>, greater<int>> pq; // Low to High
```

#### ```string```<a name="string"></a>:

+ ```string``` DOES have a ```push_back``` function

+ We can convert ```string``` to ```int``` in multiple ways. The easiest way to do this is by using the ```std::stoi()``` function introduced in C++11; The differences between ```atoi()``` and ```stoi()```: ➡️ [check here](https://stackoverflow.com/questions/20583945/what-is-the-difference-between-stdatoi-and-stdstoi)

+ convert ```string``` to ```char```:

```
string str="adcd";
char *p=(char*)str.c_str();
```

+ convert ```string``` to ```int```:

```
 std::string str = "123";
    int num;
	// using stoi() to store the value of str1 to x
    num = stoi(str);
```

+ ```stringstream```: [check here](https://www.geeksforgeeks.org/stringstream-c-applications/). We should use ```stringstream``` to eliminate the space between words in a sentence, which is a ```string```.

---

### Java <a name="Java"></a>

### Python <a name="Python"></a>