# STL

# Algorithm

## sort()

```c++
vector<int> v = {5, 2, 8, 1, 9};
sort(v.begin(), v.end()); 
// v 现在是 {1, 2, 5, 8, 9}
```

降序使用

```
sort(v.begin(), v.end(), greater<int>());
// v 现在是 {9, 8, 5, 2, 1}
```

## unique(start,end)

将相邻的重复元素移动到末尾，并返回一个指向**新逻辑末尾**的迭代器。

**例子**: 去除 `vector` 中的重复元素。

C++

```
vector<int> v = {1, 2, 2, 3, 3, 3, 4, 5};
sort(v.begin(), v.end()); 
auto last = unique(v.begin(), v.end());
v.erase(last, v.end()); // 配合 erase 真正删除元素
// v 现在是 {1, 2, 3, 4, 5}
```



## min_element()/max_element()

这两个函数可以快速找到一个范围内的最大或最小元素，并返回一个指向该元素的迭代器。

```
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 2, 8, 1, 9};
    auto min_it = std::min_element(vec.begin(), vec.end());
    auto max_it = std::max_element(vec.begin(), vec.end());
    
    std::cout << "最小元素是: " << *min_it << std::endl; // 输出 1
    std::cout << "最大元素是: " << *max_it << std::endl; // 输出 9
    return 0;
}
```



```c++
/*algorithm头文件下的常用函数
使用algorithm头文件，需要在头文件下加一行using namespace std;
常用函数
max(), min(), abs()
swap()
reverse()
next_permutation()*
fill()
sort()
lower_bound()
upper_bound()
min_element()
max_element()
copy()
find()
```

## max(), min(), abs()

```c++
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	int x=1, y=-2;
    //最大最小绝对值
	cout << max(x,y) << " " << min(x,y) << endl;
	cout << abs(x) << " " << abs(y) << endl;
	return 0;	
}
```

## swap()

swap(x,y)用来交换x和y的值

```c++
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[7]={0,1,2,3,4,5,6};
    swap(a[0],a[4]);
    for (int i = 0; i < 7; ++i) {
        cout<<a[i]<<" ";
    }
    //4 1 2 3 0 5 6
    return 0;
}
```

## reverse()

**reverse(it, it2)**可以将数组指针在$[it, it2)$之间的元素或容器的迭代器在$[it, it2)$范围内的元素

```c++
进行反转。示例如下：
/*对整形数组逆转*/
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	int a[10] = {10, 11, 12, 13, 14, 15}; 
	reverse(a, a+4);	//a[0]~a[3]反转
	for(int i=0; i<6; i++){
		cout << a[i] << " ";
	} 
	return 0;
}
/*对容器中的元素（例如string字符串）进行反转，结果也一样*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string str = "abcdefghi";
	reverse(str.begin()+2, str.begin()+6);	//对a[2]~a[5]逆转*左闭右开* 
	for(int i = 0; i < str.length(); i++){
		cout << str[i] << " ";
	} 	
	return 0;
}
```

## next_permutation()

```
//注意！只有在是个有小到大的序列
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int a[10] = {3, 2, 1};
	do{
		cout << a[0] << " " << a[1] << " " << a[2] << endl;	
	}while(next_permutation(a, a+3));
	return 0;
}
```

### fill()

fill()可以把数组或容器中的某一段区间赋为某个相同的值。和memset不同，这里的赋值可以是数组类型对应范围中的任意值。

```c++
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int a[5] = {1,2,3,4,5};
	fill(a, a+5, 233);	//将a[0]~a[4]赋值3为233 
	for(int i=0; i<5; i++){
		cout << a[i] << endl;
	}	 	
	return 0;
}
```

## sort()

sort()使用 ：sort(首元素地址(必填), 尾元素地址的下一个地址(必填), 比较函数(非必填)); 
如果不填写比较函数默认是递增数列

```c++
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int a[6] = {9, 4, 2, 5, 6, -1};
	//将a[0]~a[3]从小到大排序
	sort(a, a+4);
	for( int i = 0; i<6; i++){
		cout << *(a+i) << " ";
	} 
	cout << endl;
	sort(a, a+6);	//将a[0]~a[5]从小到大排序
	for( int i = 0; i<6; i++){
		cout << *(a+i) << " ";
	}	
	return 0;
}
/*比较函数方法一*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v{1,2,3};
	sort(v.begin(),v.end(),greater<int>());
	cout<<v.front()<<endl;
}
/*cmp函数的使用，比较函数方法二*/ 
/*(1)cmp对于整型数组*/ 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;  //可以理解为当a>b时把a放在b前面 
}
int main(){
	int a[4] = {3, 1, 4, 2};	
	sort(a, a+4, cmp);
	for(int i=0; i<4; i++){
		cout << *(a+i) << " ";
	}
	return 0;
}
/*(2)同样对char型数组*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(char a, char b){
	return a > b;  //可以理解为当a>b时把a放在b前面 
}
int main(){
	char a[4] = {'a', 'b', 'c', 'd'};	
	sort(a, a+4, cmp);
	for(int i=0; i<4; i++){
		cout << *(a+i) << " ";
	}
	return 0;
}
/*(3)对结构体数组排序*/ 
/*定义结构体：*/
struct node｛
	int x, y;
}ssd[10];
bool cmp(node a, node b)
{
	return a.x>b.x;//
}
//示例如下：
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int x, y;
}ssd[10];

bool cmp(node a,node b){
	return a.x > b.x;	//按x值从大到小对结构体数组排序 
}
int main(){
	ssd[0].x =2;ssd[0].y=2;
	ssd[1].x =1;ssd[1].y=3;
	ssd[2].x =3;ssd[2].y=1;
	sort(ssd, ssd+3, cmp);	//排序 	
	for(int i=0; i<3; i++)
		cout << ssd[i].x << endl;
	cout << " " << endl;
	return 0;
} 
```

## 查找4家族

1. `lower_bound`

**作用**：返回第一个 **大于等于 value** 的迭代器

```c++
vector<int> v = {1,2,4,4,5,7};
auto it = lower_bound(v.begin(), v.end(), 4);
// it 指向第一个 4 (下标 2)
```

**作用**：插入保持有序

```c++
v.insert(lower_bound(v.begin(), v.end(), 3), 3);
// 插入到合适位置，保持升序
```

------

2. `upper_bound`

**常见用法：**

1. **找右边界**（配合 `lower_bound`）

   ```
   auto l = lower_bound(v.begin(), v.end(), 4);
   auto r = upper_bound(v.begin(), v.end(), 4);
   cout << "4 出现次数: " << (r - l); // 2
   ```

2. **找 < value 的所有元素范围**

   ```
   auto it = upper_bound(v.begin(), v.end(), 3);
   // [v.begin(), it) 都是 <= 3 的元素
   ```

------

3. `equal_range`

**作用**：返回一个 pair，分别是 **lower_bound 和 upper_bound**

```c++
auto range = equal_range(v.begin(), v.end(), 4);
// range.first  -> 第一个 4 (下标 2)
// range.second -> 第一个大于 4 的元素 (下标 4)
```

常用于统计某个值出现的次数：

```c++
int count = range.second - range.first;  // 出现次数
```

------

4. `binary_search`

**作用**：判断有序序列中是否存在某个值，返回 `true/false`。
 实际上它是用 `lower_bound` 实现的一个封装。

```c++
bool ok = binary_search(v.begin(), v.end(), 4);  // true
bool ok2 = binary_search(v.begin(), v.end(), 6); // false
```





## copy()

```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
int main(){
    vector<int> v1{1,5,7,8,9};
    vector<int> v2{100,200,300};
    vector<double> vd{9.9,8.8,7.7,};

    cout<<"at first,v1=";
    for(int &i:v1)
        cout<<i<<" ";
    cout<<endl;
    cout<<"at first,v2=";
    for(int &i:v2)
        cout<<i<<" ";
    cout<<endl;

    auto it=copy(v2.begin(),v2.end(),v1.begin());
    //the return it is :*it=8
    cout<<"after copy(v2.begin(),v2.end(),v1.begin())"<<endl;
    cout<<"v1=";
    for(int &i:v1)
        cout<<i<<" ";
    cout<<endl;
	//v1=100 200 300 8 9 
    cout<<"v2=";
    for(int &i:v2)
            cout<<i<<" ";
   cout<<endl;
   cout<<"the return it is :*it="<<*it<<endl;
}
```

## find()

**string中的运用**
形参列表

- str：要查找的子字符串string或char变量
- pos ：要查找的起始位位置
- n：的前n个字符组成的子字符串
- 返回为参数size_type ：
  - 该子字符串首次出现时其首字符的索引；
  - 否则，返回-1

```c++
#include <iostream>
using namespace std;
int main(){
	string subString = "Let";
	string mainString = "Let life be beautiful like summer flowers,death like autumn leaves";
	char ch = subString[0];
	int isFindPosition = -1;
	isFindPosition = mainString.find(subString, isFindPosition + 1);
	cout << "isFindPosition: " << isFindPosition << endl;
}
```

**vector中的运用**
当在[first, last]查找到第一个与被查找相等的元素时，即返回查找到的元素位置，返回类型为iterator，表示元素所在的位置；若未查找到，则返回last的位置。

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<int> numbers = { 1, 2, 9, 1, 2 };
	vector<int>::iterator res;
	bool isFind;
	res = find(numbers.begin(), numbers.end(), 9);
    //res - numbers.begin()为下标
	cout << res - numbers.begin() << endl;
}
```

### Deque

#### 初始化

```C++
// 定义一个空的int类型双端队列
std::deque<int> myDeque;

// 使用初始化列表初始化一个双端队列
std::deque<int> myDeque = {1, 2, 3, 4, 5};

// 从另一个双端队列复制初始化
std::deque<int> otherDeque = {10, 20, 30};
std::deque<int> myDeque(otherDeque);

// 从数组初始化
int arr[] = {10, 20, 30, 40, 50};
std::deque<int> myDeque(arr, arr + 5);
```

### 重要操作

```C++
// 在队首插入元素
myDeque.push_front(0);

// 在队尾插入元素
myDeque.push_back(6);

// 移除队首元素
myDeque.pop_front();

// 移除队尾元素
myDeque.pop_back();

// 访问队首元素，不移除
myDeque.front();

// 访问队尾元素，不移除
myDeque.back();

// 访问指定位置的元素，类似于数组
myDeque[2];

// 插入一个或多个元素到指定位置
myDeque.insert(myDeque.begin() + 2, 99);

// 删除指定位置的元素
myDeque.erase(myDeque.begin() + 1);

// 返回双端队列中元素的个数
myDeque.size();

// 判断双端队列是否为空
myDeque.empty();

// 清空双端队列中的所有元素
myDeque.clear();

// 返回指向第一个元素的迭代器
myDeque.begin();

// 返回指向双端队列末尾(最后一个元素之后)的迭代器
myDeque.end();
```

------

### 备注

- **1、双端操作**
  - `std::deque` (double-ended queue) 可以在队首和队尾高效地执行插入和删除操作，时间复杂度为 `O(1)`。
- **2、随机访问**
  - `std::deque` 支持随机访问，可以用 `[]` 或 `at()` 像数组一样访问任意元素，时间复杂度为 `O(1)`。
- **3、内存管理**
  - `std::deque` 不是连续存储的，它由一系列独立的固定大小的块组成，并通过一个中控器管理这些块。这使得其在两端插入或删除元素时不需要重新分配和复制整个容器，但相比 `std::vector`，迭代器和指针的稳定性较差。
- **4、适用场景**
  - `std::deque` 适用于需要频繁在两端进行插入和删除操作，并且偶尔需要随机访问元素的场景。如果只在尾部操作，`std::vector` 通常更快；如果只在两端操作，`std::deque` 比 `std::list` 更高效且支持随机访问。
- **5、与 `vector` 的区别**
  - `vector` 是一段连续的内存，不支持在头部的快速插入和删除。
  - `deque` 由分段的内存组成，支持在头尾的快速插入和删除。
- **6、与 `list` 的区别**
  - `list` 是一个双向链表，插入和删除操作可以在任意位置高效完成，但不支持随机访问。
  - `deque` 可以在两端高效操作，并支持随机访问，但中间位置的插入和删除相对较慢。



# Vector

## 初始化

```c++
//定义了10个整型元素的向量，其值是不确定的。
vector<int> a(10); 
//定义了10个整型元素的向量,且给出每个元素的初值为1
vector<int> a(10,1); 
//用b向量来创建a向量，整体复制性赋值
vector<int> a(b); 
//定义了a值为b中第0个到第2个（共3个）元素
vector<int> a(b.begin(),b.begin+3); 
//从数组中获得初值
vector<int> a(b,b+7); 

//二维
// 初始化 3x4 的二维vector，所有元素为0
vector<vector<int>> matrix(3, vector<int>(4));

// 初始化 5x5 的二维vector，所有元素为默认值
vector<vector<double>> grid(5, vector<double>(5));

// 初始化 2x3 的二维vector，所有元素为-1
vector<vector<int>> matrix(2, vector<int>(3, -1));

// 初始化 4x2 的二维vector，所有元素为true
vector<vector<bool>> flags(4, vector<bool>(2, true));
```

## 重要操作

- **a.assign(b.begin(), b.begin()+3)**
  - b为向量，将b的0~2个元素构成的向量赋a
- **a.assign(4,2)**
  - 是a只含4个元素，且每个元素为2
- **a.back();** 
  - 返回a的最后一个元素
- **a.front();**
  - 返回a的第一个元素
- **a.clear()**
  - 清空a中的元素
- **a.empty()**
  - 判断a是否为空，空则返回ture,不空则返回false
- **a.pop_back()**
  - 删除a向量的最后一个元素
- **a.erase(a.begin()+1,a.begin()+3)**
  - 删除a中第1个（从第0个算起）到第2个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+3（不包括它）
- **a.push_back(5)**
  - 在a的最后一个向量后插入一个元素，其值为5
- **a.insert(a.begin()+1,5)**
  - 在a的第1个元素（从第0个算起）的位置插入数值5，如a为1,2,3,4，插入元素后为1,5,2,3,4
- **a.insert(a.begin()+1,3,5)**
  - 在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5
- **a.insert(a.begin()+1,b+3,b+6)**
  - b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6），如b为1,2,3,4,5,9,8，插入元素后为1,4,5,9,2,3,4,5,9,8
- **a.size()**
  - 返回a中元素的个数；
- **a.capacity()**
  - 返回a在内存中总共可以容纳的元素个数
- **a.resize(10)**
  - 将a的现有元素个数调至10个，多则删，少则补，其值随机
- **a.resize(10,2)**
  - 将a的现有元素个数调至10个，多则删，少则补，其值为2
- **a.reserve(100)**
  - 将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能） 
- **a==b**
  - b为向量，向量的比较操作还有!=,>=,<=,>,<

## 备注

```c++
//1、添加i
vector<int> a;
for(int i=0;i<10;i++)
	a.push_back(i);

//2、也可以从数组中选择元素向向量中添加
int a[6]={1,2,3,4,5,6};
vector<int> b；
for(int i=1;i<=4;i++)
	b.push_back(a[i]);

//3、也可以从现有向量中选择元素向向量中添加
int a[6]={1,2,3,4,5,6};
vector<int> b;
vector<int> c(a,a+4);
for(vector<int>::iterator it=c.begin();it<c.end();it++)
	b.push_back(*it);

//4、也可以从文件中读取元素向向量中添加
ifstream in("data.txt");
vector<int> a;
for(int i; in>>i)
    a.push_back(i);

//5、误区
vector<int> a;
for(int i=0;i<10;i++)
    a[i]=i;
//这种做法以及类似的做法都是错误的。刚开始我也犯过这种错误，后来发现，下标只能用于获取已存在的元素，可以进行修改而现在的a[i]还是空的对象
```

# Set

## 初始化

```
// 定义一个空的int类型集合
std::set<int> mySet;

// 使用初始化列表初始化一个集合
std::set<int> mySet = {3, 1, 4, 1, 5, 9, 2, 6};
// 集合会自动排序并去重，mySet最终包含 {1, 2, 3, 4, 5, 6, 9}

// 从另一个集合复制初始化
std::set<int> otherSet = {1, 2, 3};
std::set<int> mySet(otherSet);

// 从数组初始化
int arr[] = {10, 20, 30, 10, 50};
std::set<int> mySet(arr, arr + 5);
// mySet最终包含 {10, 20, 30, 50}
```

------

## 重要操作

```c++
mySet.insert(7);
// 插入一个元素，如果元素已存在则不执行任何操作

mySet.erase(3);
// 删除值为3的元素

mySet.find(5);
// 查找值为5的元素，返回指向该元素的迭代器；如果不存在则返回end()

mySet.count(1);
// 返回值为1的元素数量，由于set中元素唯一，所以只可能返回0或1

mySet.size();
// 返回集合中元素的个数

mySet.empty();
// 判断集合是否为空，空则返回true

mySet.clear();
// 清空集合中的所有元素

mySet.begin();
// 返回指向第一个元素的迭代器

mySet.end();
// 返回指向集合末尾(最后一个元素之后)的迭代器
```

## 备注

```c++
// 1、元素唯一性
// set容器中的所有元素都是唯一的，重复的元素会被自动忽略。

// 2、自动排序
// 默认情况下，set中的元素是按升序自动排序的。你可以在初始化时使用std::greater来自定义排序顺序。
// std::set<int, std::greater<int>> mySet;

// 3、元素不可修改
// set中的元素一旦插入后就不能直接修改其值。如果需要修改，必须先删除旧元素，再插入新元素。

// 4、高效操作
// set通常由红黑树实现，因此查找、插入和删除操作的时间复杂度为O(logN)，效率很高。

// 5、multiset
// multiset与set相似，但允许存储重复的元素，且同样保持元素有序。
// 示例：std::multiset<int> myMultiset = {1, 5, 1, 3}; 最终包含 {1, 1, 3, 5}。

// 6、unordered_set
// unordered_set 不对元素进行排序，而是通过哈希表来组织。
// 这使得其在平均情况下，查找、插入和删除操作的时间复杂度为O(1)，但没有序性。
// 示例：std::unordered_set<int> myUnorderedSet = {3, 1, 4, 1}; 最终包含 {1, 3, 4}，但顺序不确定。
```

# Map

## 初始化

```c++
// 定义一个空的map，键为int类型，值为string类型
std::map<int, std::string> myMap;

// 使用初始化列表初始化一个map
std::map<int, std::string> myMap = {
    {1, "Apple"},
    {2, "Banana"},
    {3, "Cherry"}
};

// 从另一个map复制初始化
std::map<int, std::string> otherMap = {{1, "One"}};
std::map<int, std::string> myMap(otherMap);
```

## 重要操作

```c++
// 插入一个元素（键值对）
myMap.insert({4, "Date"});
myMap.insert(std::pair<int, std::string>(5, "Elderberry"));

// 使用[]操作符插入或访问元素
myMap[6] = "Fig"; // 插入新键值对
std::string fruit = myMap[1]; // 访问键为1的值

// 使用at()访问元素，若键不存在会抛出异常
myMap.at(2) = "Grape";

// 删除键为3的元素
myMap.erase(3);

// 查找键为5的元素，返回指向该元素的迭代器；如果不存在则返回end()
myMap.find(5);

// 返回键为6的元素数量，由于map中键唯一，所以只可能返回0或1
myMap.count(6);

// 返回map中元素的个数
myMap.size();

// 判断map是否为空，空则返回true
myMap.empty();

// 清空map中的所有元素
myMap.clear();

// 返回指向第一个元素的迭代器（按键的排序）
myMap.begin();

// 返回指向map末尾(最后一个元素之后)的迭代器
myMap.end();

for (auto &p : mp) {
    cout << p.first << " : " << p.second << endl;
}
```

## 备注

```c++
void f() {
   map<int, string> m = {
    {0, "a"},
    {1, "b"},  
  };
   for (const auto &[i, s] : m) {
       cout << i << " " << s << endl;
  }
}


// 1、键的唯一性
// map容器中的所有键都是唯一的，重复的键值对会被忽略，或通过[]操作符覆盖旧值。

// 2、自动排序
// 默认情况下，map中的元素是按键的升序自动排序的。

// 3、高效操作
// map通常由红黑树实现，因此查找、插入和删除操作的时间复杂度为O(logN)，效率很高。

// 4、multimap
// multimap与map相似，但允许存储重复的键，且同样保持元素有序。
// 示例：std::multimap<int, std::string> myMultimap = {{1, "A"}, {2, "B"}, {1, "C"}};
// 最终包含 { (1,"A"), (1,"C"), (2,"B") }。

// 5、unordered_map
// unordered_map 不对元素进行排序，而是通过哈希表来组织。
// 这使得其在平均情况下，查找、插入和删除操作的时间复杂度为O(1)，但没有序性。
// 示例：std::unordered_map<int, std::string> myUnorderedMap = {{3, "C"}, {1, "A"}}; 
// 最终包含 { (1,"A"), (3,"C") }，但顺序不确定。
```

# Stack

基本操作

- push()
- pop()
- top()
- empty()

```c++
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;
    
    // 压入元素
    s.push(10);
    s.push(20);
    s.push(30);
    
    // 访问栈顶元素
    std::cout << "栈顶元素: " << s.top() << std::endl; // 输出 30
    
    // 弹出元素
    s.pop(); // 移除30
    std::cout << "弹出后栈顶元素: " << s.top() << std::endl; // 输出 20
    
    // 检查栈是否为空
    if (!s.empty()) {
        std::cout << "栈不为空" << std::endl;
    }
    
    // 获取栈的大小
    std::cout << "栈中元素数量: " << s.size() << std::endl;
    
    return 0;
}
```

# Queue

## 初始化

```c++
// 定义一个空的int类型队列
std::queue<int> myQueue;

// queue是一个适配器，默认使用std::deque作为底层容器
// 也可以指定其他容器，比如std::list
std::queue<int, std::list<int>> myQueueList;
```

## 重要操作

```c++
// 在队列末尾插入一个元素
myQueue.push(10);
myQueue.push(20);

// 返回队列 front 端的元素
int front_element = myQueue.front(); // 结果为 10

// 返回队列 back 端的元素
int back_element = myQueue.back();   // 结果为 20

// 移除队列 front 端的元素
myQueue.pop(); // 移除 10

// 返回队列中元素的个数
size_t queue_size = myQueue.size(); // 结果为 1

// 判断队列是否为空，空则返回 true
bool is_empty = myQueue.empty();
```

## 备注

```c++
// 1、先进先出 (FIFO)
// queue是一种先进先出的数据结构，元素从队尾加入 (push)，从队头移除 (pop)。

// 2、容器适配器
// queue本身不是一个完整的容器，而是一个“容器适配器”，它封装了基础容器（如deque或list），并提供受限的接口来实现FIFO行为。

// 3、没有迭代器
// queue不支持迭代器，你不能像访问 vector 或 set 那样遍历它的元素。你只能访问队头和队尾。

// 4、Priority Queue
// priority_queue是另一个重要的容器适配器，它总是将优先级最高的元素放在队头（默认为最大值）。
// 它与 queue 的区别在于，它不是按存入顺序移除，而是按元素优先级移除。
// 示例：std::priority_queue<int> myPQ; myPQ.push(3); myPQ.push(5); myPQ.push(1); 
// 此时 myPQ.top() 结果为 5。
```

### Priority Queue

## 初始化

```c++
// 定义一个空的int类型优先队列，默认是一个大顶堆
std::priority_queue<int> max_pq;

// 优先队列是一个适配器，默认使用std::vector作为底层容器
// 也可以指定其他容器，比如std::deque
std::priority_queue<int, std::deque<int>> another_pq;
```

## 重要操作

```c++
// 在队列中插入一个元素
max_pq.push(10);
max_pq.push(30);
max_pq.push(20);

// 返回队列中优先级最高的元素（大顶堆中是最大值）
int top_element = max_pq.top(); // 结果为 30

// 移除队列中优先级最高的元素
max_pq.pop(); // 移除 30

// 返回队列中元素的个数
size_t pq_size = max_pq.size(); // 结果为 2

// 判断队列是否为空，空则返回 true
bool is_empty = max_pq.empty();
```

## 备注

```c++
// 1、容器适配器
// priority_queue本身不是一个完整的容器，它封装了基础容器（如vector或deque），并提供受限的接口来实现优先级排序。

// 2、默认行为：大顶堆
// 默认情况下，priority_queue使用std::less作为比较器，使得优先级最高的元素是最大值。

// 3、修改优先级函数
// 通过修改模板参数可以改变排序规则。
// 小顶堆（最小值优先）：
// std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;

// 自定义比较函数（适用于自定义对象）：
// struct Compare {
//     bool operator()(const MyClass& a, const MyClass& b) {
//         return a.score < b.score; // 示例：按分数降序排序
//     }
// };
// std::priority_queue<MyClass, std::vector<MyClass>, Compare> my_pq;

// 4、没有迭代器
// priority_queue不支持迭代器，你不能遍历它的所有元素，只能通过top()访问优先级最高的元素。

// 5、高效操作
// 插入和删除操作的时间复杂度为O(logN)，因为它们依赖于底层堆结构的调整。
```

# Pair

```C++
//定义
pair<int, string> p1(1, "apple");
//生成
auto p2 = make_pair(2, "banana");
//访问
cout << p2.first << " " << p2.second << endl;
```

# Tuple

```c++
//定义
tuple<int, string, double> t1(1, "apple", 3.14);
//生成
auto t2 = make_tuple(2, "banana", 6.28);
访问
cout << get<0>(t1) << endl; // 1
cout << get<1>(t1) << endl; // apple
cout << get<2>(t1) << endl; // 3.14
auto [id, name, value] = t1;
cout << id << " " << name << " " << value << endl;

```

# List

## 初始化

```c++
// 定义一个空的int类型链表
std::list<int> myList;

// 使用初始化列表初始化一个链表
std::list<int> myList = {3, 1, 4, 1, 5, 9};
// 链表会保持插入的顺序，myList 包含 {3, 1, 4, 1, 5, 9}

// 创建一个包含5个值为100的元素的链表
std::list<int> myList(5, 100); // -> {100, 100, 100, 100, 100}

// 从另一个链表复制初始化
std::list<int> otherList = {1, 2, 3};
std::list<int> myList(otherList);

// 从数组初始化
int arr[] = {10, 20, 30, 40, 50};
std::list<int> myList(arr, arr + 5);
// myList 最终包含 {10, 20, 30, 40, 50}
```

## 重要操作

```c++
myList.push_back(7);// 在链表尾部添加一个元素
myList.push_front(0);// 在链表头部添加一个元素
myList.pop_back();// 删除链表尾部的元素
myList.pop_front();// 删除链表头部的元素

myList.front();// 返回对链表第一个元素的引用
myList.back();// 返回对链表最后一个元素的引用

auto it = myList.begin();
it++; // 迭代器移动到第二个元素
cout<<*it;//获得对应内容

myList.insert(it, 99);
// 在指定迭代器位置之前插入元素

auto it_to_erase = myList.begin();
auto next_i = myList.erase(it_to_erase);
// 删除指定迭代器位置的元素，返回下一个节点

myList.size();// 返回链表中元素的个数
myList.empty();// 判断链表是否为空，空则返回true
myList.clear();// 清空链表中的所有元素
myList.begin();// 返回指向第一个元素的迭代器
myList.end();// 返回指向链表末尾(最后一个元素之后)的迭代器
```



#### 备注

1. **双向链表** `std::list` 是一个双向链表容器。每个元素都存储了指向前一个和后一个元素的指针。这使得在任何位置插入和删除元素都非常高效。
2. **不支持随机访问** 由于其非连续内存存储的特性，`std::list` 不支持通过 `[]` 运算符或 `at()` 函数进行快速随机访问。要访问特定位置的元素，必须从头或尾部开始遍历。
3. **高效的插入和删除** 在链表的任何位置进行插入和删除操作的时间复杂度都是 O(1)（常数时间），前提是已经有了指向该位置的迭代器。这是 `std::list` 相对于 `std::vector` 的最大优势。
4. **迭代器稳定性** 对 `std::list` 进行插入或删除操作不会使指向其他元素的迭代器、指针或引用失效。只有指向被删除元素的迭代器会失效。
5. **额外内存开销** 与 `std::vector` 相比，`std::list` 的每个元素都需要额外的空间来存储前向和后向指针，因此内存占用会更大。
6. **特有成员函数** `std::list` 提供了一些 `std::vector` 或 `std::deque` 没有的特殊成员函数，用于高效地操作链表结构，例如：
   - `splice()`: 将一个链表的元素移动到另一个链表。
   - `remove()`: 删除所有等于特定值的元素。
   - `sort()`: 对链表进行排序。
   - `merge()`: 合并两个已排序的链表。
   - `reverse()`: 反转链表中元素的顺序。
7. **`forward_list`** C++11 引入了 `std::forward_list`，它是一个单向链表，只存储指向下一个元素的指针。它比 `std::list` 更节省内存，但只支持前向迭代。

# String

## 初始化

```c++
// 定义一个空的字符串
string s1; 

// 从C-风格字符串字面量初始化
string s2 = "Hello World";

// 从另一个字符串对象复制初始化
string s3 = s2;

// 用子串初始化
// 从s2的第6个字符（索引从0开始）开始，取5个字符
string s4(s2, 6, 5); // s4 为 "World"

// 用多个相同字符初始化
// s5 为 "aaaaa"
string s5(5, 'a'); 
```

## 重要操作

```c++
// 获取字符串长度
size_t len = s2.length(); // 也可以用s2.size()

// 判断字符串是否为空
bool is_empty = s1.empty();

// 访问单个字符
char first_char = s2[0]; // 'H'
char last_char = s2.at(s2.length() - 1); // 'd'

// 获取C-风格字符串
const char* c_str_ptr = s2.c_str(); 

// --- 添加/拼接操作 ---
string s_new = "Hello";
s_new.push_back('!'); // s_new 变为 "Hello!"

// 拼接字符串
s_new.append(" World"); // s_new 变为 "Hello! World"
s_new.append(" Nice", 4); // 拼接前4个字符，s_new 变为 "Hello! World Nice"

// 从指定位置插入字符串
string s_insert = "World";
s_insert.insert(0, "Hello "); // s_insert 变为 "Hello World"
s_insert.insert(5, " Beautiful", 5); // 插入 "Beautiful" 的前5个字符，s_insert 变为 "Hello BeautWorld"

// 在指定位置插入重复字符
s_insert.insert(5, 3, '!'); // s_insert 变为 "Hello!!!BeautWorld"

// --- 查找/获取操作 ---
string s_find = "Hello World World";

// 查找子串，返回第一个匹配的索引
size_t pos1 = s_find.find("World"); // pos1 为 6

// 从指定位置开始查找
size_t pos2 = s_find.find("World", 7); // pos2 为 12

// 从末尾开始反向查找子串
size_t pos3 = s_find.rfind("World"); // pos3 为 12

// 查找单个字符
size_t pos4 = s_find.find('l'); // pos4 为 2

// 提取子串
string sub1 = s_find.substr(6); // 从索引6到末尾，sub1为 "World World"
string sub2 = s_find.substr(6, 5); // 从索引6开始，取5个字符，sub2为 "World"

// --- 替换/删除操作 ---
string s_replace = "I like bananas";

// 替换子串
// 从索引7开始，替换7个字符为"apples"
s_replace.replace(7, 7, "apples"); // s_replace 变为 "I like apples"

// 使用重复字符替换
// 从索引2开始，替换3个字符为"---"
s_replace.replace(2, 3, 3, '-'); // s_replace 变为 "I --- apples"

// 从指定位置删除字符
s_replace.erase(2, 3); // 从索引2开始，删除3个字符，s_replace 变为 "I  apples"

// 清空字符串
s_replace.clear();
```

## 遍历

主要有三种方法遍历 `string`：下标法、正向迭代器和反向迭代器。

1. **下标法：** `for (int i = 0; i < s1.size(); ++i) { cout << s1[i]; }`
2. **正向迭代器：** `for (string::iterator it = s1.begin(); it != s1.end(); ++it) { cout << *it; }`
3. **反向迭代器：** `for (string::reverse_iterator rit = s1.rbegin(); rit != s1.rend(); ++rit) { cout << *rit; }`

## 备注

```
// 1、内存管理
// string 是一个类，它会自动管理内存。当你添加或删除字符时，它会自动进行内存分配和释放，比C风格的字符数组更安全和方便。

// 2、与C-风格字符串的区别
// string 是一段字符序列，它知道自己的长度，且可以动态改变大小。
// C-风格字符串（char*）本质是一个字符数组，以空字符('\0')结尾来表示结束，需要手动管理内存，且容易发生缓冲区溢出。

// 3、性能
// string 很多操作（如拼接、插入）在内部可能涉及内存重新分配和数据拷贝，如果需要频繁操作，可能会有性能开销。可以使用 reserve() 方法来预留内存。

// 4、迭代器
// string 提供了迭代器，可以像遍历vector一样遍历它。
// for (char c : s2) { /* ... */ }
```

## 构造函数

`string` 类提供了多种构造函数，用于创建和初始化字符串对象。

- **空字符串：** `string s;`
- **拷贝构造：** `string s(str);` // `str` 为一个已存在的 `string` 对象
- **从 C-style 字符串构造：** `string s(cstr);` // `cstr` 为一个 C-style 字符串 (`const char*`)
- **子串构造：** `string s(str, pos, len);` // 从 `str` 的 `pos` 位置开始，复制 `len` 个字符
- **重复字符构造：** `string s(num, c);` // 创建包含 `num` 个字符 `c` 的字符串

**示例:**

```
// 结果：
// str2:123456789
// str3:123
// str4:01234
// str5:11111
// str6:3456789
```

- `string str1;` // 空字符串
- `string str2("123456789");`
- `string str3("12345", 0, 3);` // 结果为 "123"
- `string str4("0123456", 5);` // 结果为 "012345" 的前5个字符，即 "01234"
- `string str5(5, '1');` // 结果为 "11111"
- `string str6(str2, 2);` // 从 `str2` 的索引2开始到末尾，结果为 "3456789"

------

## 大小与容量

- **`size()` 和 `length()`：** 返回字符串中的字符数。两者功能相同。
- **`max_size()`：** 返回 `string` 对象理论上能包含的最大字符数。
- **`capacity()`：** 返回在不重新分配内存的情况下，字符串能容纳的最大字符数。

**示例:**

```
string s("1234567");
cout << "size=" << s.size() << endl;       // 输出: 7
cout << "length=" << s.length() << endl;   // 输出: 7
cout << "max_size=" << s.max_size() << endl; // 很大，取决于系统
cout << "capacity=" << s.capacity() << endl; // 大于或等于size
```

------



#### **三、字符串比较**



`string` 支持常用的比较操作符 (`<`, `<=`, `==`, `!=`, `>`, `>=`) 以及 `compare()` 成员函数。

1. **比较操作符：** 基于字典序逐个字符进行比较。如果两个字符串长度不同但前缀相同，较短的字符串小于较长的。
2. **`compare()` 函数：** 功能更强大，支持子串比较。返回值：
   - `0`：相等
   - `>0`：调用者大于参数
   - `<0`：调用者小于参数

**示例:**

C++

```
string A("aBcd"), B("Abcd"), C("123456"), D("123dfg");

cout << "A.compare(B):" << A.compare(B) << endl;         // a > A, 结果: 1
cout << "A.compare(2, 3, B):" << A.compare(2, 3, B) << endl; // "cd " vs "Abc", c > A, 结果: 1
cout << "A.compare(2, 3, B, 2, 3):" << A.compare(2, 3, B, 2, 3) << endl; // "cd " vs "cd ", 结果: 0
cout << "C.compare(0, 3, D, 0, 3):" << C.compare(0, 3, D, 0, 3) << endl; // "123" vs "123", 结果: 0
```

**注意：** 您的示例 `A.compare(2, 3, B)` 结果为 `1` 是正确的，但其比较的是 `A` 的子串 `"cd"` 和 `B` 的 `"Abc"`。

------



#### **四、插入和追加**



- **`push_back()`：** 在字符串末尾添加单个字符。
- **`insert()`：** 在指定位置插入字符或子串。
- **`append()` 和 `+` 操作符：** 用于拼接字符串。

**示例:**

C++

```
string s1;
s1.push_back('a'); // s1: "a"
s1.push_back('b'); // s1: "ab"
s1.push_back('c'); // s1: "abc"
s1.insert(s1.begin(), '1'); // s1: "1abc"

string s2("abc");
s2.append("def"); // s2: "abcdef"

string s3 = "ghi";
string s4 = s2 + s3; // s4: "abcdefghi"
```

------



#### **五、遍历**



主要有三种方法遍历 `string`：下标法、正向迭代器和反向迭代器。

1. **下标法：** `for (int i = 0; i < s1.size(); ++i) { cout << s1[i]; }`
2. **正向迭代器：** `for (string::iterator it = s1.begin(); it != s1.end(); ++it) { cout << *it; }`
3. **反向迭代器：** `for (string::reverse_iterator rit = s1.rbegin(); rit != s1.rend(); ++rit) { cout << *rit; }`

------



#### **六、删除**



- **`erase()`：** 删除指定位置或范围的字符。
  - `s.erase(pos, len)`：从 `pos` 开始删除 `len` 个字符。
  - `s.erase(it)`：删除迭代器 `it` 所指的字符。
  - `s.erase(first, last)`：删除迭代器区间 `[first, last)` 的字符。
- **`clear()`：** 删除所有字符，使字符串变为空。

**示例:**

C++

```
string s1 = "123456789";
s1.erase(1, 6); // 从索引1开始删除6个字符，即"234567"，结果为 "189"
```

------



#### **七、替换**



`replace()` 函数用于替换字符串中的子串或字符。

**示例:**

C++

```
string s1("hello,world!");
s1.replace(s1.size() - 1, 1, 1, '.'); // 将最后一个字符'!'替换为'.'，结果: "hello,world."
s1.replace(6, 5, "girl"); // 从索引6开始替换5个字符("world")为"girl"，结果: "hello,girl."
s1.replace(s1.begin(), s1.begin() + 5, "boy"); // 替换迭代器区间[begin(), begin()+5)的字符("hello")为"boy"，结果: "boy,girl."
```



#### **八、大小写转换**

可以使用 C 库函数 `tolower()`, `toupper()` 或 STL 算法 `transform()`。

**方法一：循环遍历**

C++

```
string s = "ABCDEFG";
for (int i = 0; i < s.size(); ++i) {
    s[i] = tolower(s[i]);
}
cout << s << endl; // 结果: "abcdefg"
```

**方法二：`transform` 算法**

C++

```
#include <algorithm>
// ...
string s = "ABCDEFG";
transform(s.begin(), s.end(), s.begin(), ::tolower);
cout << s << endl; // 结果: "abcdefg"
```

------



#### **九、查找**

`string` 提供了多种查找函数，返回找到的位置索引，未找到则返回 `string::npos`（通常是 `-1`）。

- **`find()`：** 从前往后查找。
  - `find(const char* s, pos)`: 查找子串。
  - `find(char c, pos)`: 查找字符。
- **`rfind()`：** 从后往前查找。
  - `rfind(const char* s, pos)`: 查找子串。
  - `rfind(char c, pos)`: 查找字符。
- **`find_first_of()`：** 查找第一个属于指定字符集的字符。
- **`find_first_not_of()`：** 查找第一个不属于指定字符集的字符。
- **`find_last_of()`：** 查找最后一个属于指定字符集的字符。
- **`find_last_not_of()`：** 查找最后一个不属于指定字符集的字符。

**示例:**

```
string s("dog bird chicken bird cat");

cout << s.find("chicken") << endl;               // 结果: 9
cout << s.rfind("bird") << endl;                 // 结果: 15
cout << s.find_first_of("13br98") << endl;        // 结果: 4 (第一个找到的字符是 'b')
cout << s.find_last_not_of("teac") << endl;      // 结果: 21 (最后一个不属于 "teac" 的字符是 ' ' )
```

------



#### **十、排序、分割和截取**

- **排序：** 使用 STL 的 `sort()` 算法对字符串进行排序。 `sort(s.begin(), s.end());`
- **分割：** 使用 C 语言的 `strtok()` 函数。
- **截取子串：** 使用 `substr()` 函数。 `string s.substr(pos, len);` // 从 `pos` 位置开始，截取长度为 `len` 的子串。

**示例:**

C++

```
// 排序
string s_sort = "cdefba";
sort(s_sort.begin(), s_sort.end());
cout << s_sort << endl; // 结果: "abcdef"

// 分割 (strtok)
char str[] = "I,am,a,student; hello world!";
const char *split = ",; !";
char *p2 = strtok(str, split);
while (p2 != NULL) {
    cout << p2 << endl; // 逐行输出分割后的子串
    p2 = strtok(NULL, split);
}

// 截取 (substr)
string s_sub = "0123456789";
string s2 = s_sub.substr(2, 5); // 从索引2开始，截取5个字符
cout << s2 << endl; // 结果: "23456"
```

```c++
C++ string 类
一、构造函数
string 类提供了多种构造函数，用于创建和初始化字符串对象。

空字符串：
string s;

拷贝构造：
string s(str); // str 为一个已存在的 string 对象

从 C-style 字符串构造：
string s(cstr); // cstr 为一个 C-style 字符串 (const char*)

子串构造：
string s(str, pos, len); // 从 str 的 pos 位置开始，复制 len 个字符

重复字符构造：
string s(num, c); // 创建包含 num 个字符 c 的字符串

示例:

C++

// 结果：
// str2:123456789
// str3:123
// str4:01234
// str5:11111
// str6:3456789
string str1; // 空字符串

string str2("123456789");

string str3("12345", 0, 3); // 结果为 "123"

string str4("0123456", 5); // 结果为 "012345" 的前5个字符，即 "01234"

string str5(5, '1'); // 结果为 "11111"

string str6(str2, 2); // 从 str2 的索引2开始到末尾，结果为 "3456789"

二、大小与容量
size() 和 length()： 返回字符串中的字符数。两者功能相同。

max_size()： 返回 string 对象理论上能包含的最大字符数。

capacity()： 返回在不重新分配内存的情况下，字符串能容纳的最大字符数。

示例:

C++

string s("1234567");
cout << "size=" << s.size() << endl;       // 输出: 7
cout << "length=" << s.length() << endl;   // 输出: 7
cout << "max_size=" << s.max_size() << endl; // 很大，取决于系统
cout << "capacity=" << s.capacity() << endl; // 大于或等于size
三、字符串比较
string 支持常用的比较操作符 (<, <=, ==, !=, >, >=) 以及 compare() 成员函数。

比较操作符：
基于字典序逐个字符进行比较。如果两个字符串长度不同但前缀相同，较短的字符串小于较长的。

compare() 函数：
功能更强大，支持子串比较。返回值：

0：相等

>0：调用者大于参数

<0：调用者小于参数

示例:

C++

string A("aBcd"), B("Abcd"), C("123456"), D("123dfg");

cout << "A.compare(B):" << A.compare(B) << endl;         // a > A, 结果: 1
cout << "A.compare(2, 3, B):" << A.compare(2, 3, B) << endl; // "cd " vs "Abc", c > A, 结果: 1
cout << "A.compare(2, 3, B, 2, 3):" << A.compare(2, 3, B, 2, 3) << endl; // "cd " vs "cd ", 结果: 0
cout << "C.compare(0, 3, D, 0, 3):" << C.compare(0, 3, D, 0, 3) << endl; // "123" vs "123", 结果: 0
注意： 您的示例 A.compare(2, 3, B) 结果为 1 是正确的，但其比较的是 A 的子串 "cd" 和 B 的 "Abc"。

四、插入和追加
push_back()： 在字符串末尾添加单个字符。

insert()： 在指定位置插入字符或子串。

append() 和 + 操作符： 用于拼接字符串。

示例:

C++

string s1;
s1.push_back('a'); // s1: "a"
s1.push_back('b'); // s1: "ab"
s1.push_back('c'); // s1: "abc"
s1.insert(s1.begin(), '1'); // s1: "1abc"

string s2("abc");
s2.append("def"); // s2: "abcdef"

string s3 = "ghi";
string s4 = s2 + s3; // s4: "abcdefghi"
五、遍历
主要有三种方法遍历 string：下标法、正向迭代器和反向迭代器。

下标法：
for (int i = 0; i < s1.size(); ++i) { cout << s1[i]; }

正向迭代器：
for (string::iterator it = s1.begin(); it != s1.end(); ++it) { cout << *it; }

反向迭代器：
for (string::reverse_iterator rit = s1.rbegin(); rit != s1.rend(); ++rit) { cout << *rit; }

六、删除
erase()： 删除指定位置或范围的字符。

s.erase(pos, len)：从 pos 开始删除 len 个字符。

s.erase(it)：删除迭代器 it 所指的字符。

s.erase(first, last)：删除迭代器区间 [first, last) 的字符。

clear()： 删除所有字符，使字符串变为空。

示例:

C++

string s1 = "123456789";
s1.erase(1, 6); // 从索引1开始删除6个字符，即"234567"，结果为 "189"
七、替换
replace() 函数用于替换字符串中的子串或字符。

示例:

C++

string s1("hello,world!");
s1.replace(s1.size() - 1, 1, 1, '.'); // 将最后一个字符'!'替换为'.'，结果: "hello,world."
s1.replace(6, 5, "girl"); // 从索引6开始替换5个字符("world")为"girl"，结果: "hello,girl."
s1.replace(s1.begin(), s1.begin() + 5, "boy"); // 替换迭代器区间[begin(), begin()+5)的字符("hello")为"boy"，结果: "boy,girl."
八、大小写转换
可以使用 C 库函数 tolower(), toupper() 或 STL 算法 transform()。

方法一：循环遍历

C++

string s = "ABCDEFG";
for (int i = 0; i < s.size(); ++i) {
    s[i] = tolower(s[i]);
}
cout << s << endl; // 结果: "abcdefg"
方法二：transform 算法

C++

#include <algorithm>
// ...
string s = "ABCDEFG";
transform(s.begin(), s.end(), s.begin(), ::tolower);
cout << s << endl; // 结果: "abcdefg"
九、查找
string 提供了多种查找函数，返回找到的位置索引，未找到则返回 string::npos（通常是 -1）。

find()： 从前往后查找。

find(const char* s, pos): 查找子串。

find(char c, pos): 查找字符。

rfind()： 从后往前查找。

rfind(const char* s, pos): 查找子串。

rfind(char c, pos): 查找字符。

find_first_of()： 查找第一个属于指定字符集的字符。

find_first_not_of()： 查找第一个不属于指定字符集的字符。

find_last_of()： 查找最后一个属于指定字符集的字符。

find_last_not_of()： 查找最后一个不属于指定字符集的字符。

示例:

C++

string s("dog bird chicken bird cat");

cout << s.find("chicken") << endl;               // 结果: 9
cout << s.rfind("bird") << endl;                 // 结果: 15
cout << s.find_first_of("13br98") << endl;        // 结果: 4 (第一个找到的字符是 'b')
cout << s.find_last_not_of("teac") << endl;      // 结果: 21 (最后一个不属于 "teac" 的字符是 ' ' )
十、排序、分割和截取
排序： 使用 STL 的 sort() 算法对字符串进行排序。
sort(s.begin(), s.end());

分割： 使用 C 语言的 strtok() 函数。

截取子串： 使用 substr() 函数。
string s.substr(pos, len); // 从 pos 位置开始，截取长度为 len 的子串。

示例:

C++

// 排序
string s_sort = "cdefba";
sort(s_sort.begin(), s_sort.end());
cout << s_sort << endl; // 结果: "abcdef"

// 分割 (strtok)
char str[] = "I,am,a,student; hello world!";
const char *split = ",; !";
char *p2 = strtok(str, split);
while (p2 != NULL) {
    cout << p2 << endl; // 逐行输出分割后的子串
    p2 = strtok(NULL, split);
}

// 截取 (substr)
string s_sub = "0123456789";
string s2 = s_sub.substr(2, 5); // 从索引2开始，截取5个字符
cout << s2 << endl; // 结果: "23456"
```

# Bitset

**初始化**

```
#include <bitset>

// 定义一个长度为 8 的 bitset（下标 0 表示最低位）
bitset<8> bs;              // 默认全 0
bitset<8> bs2(10);         // 用整数初始化（10 的二进制 00001010）
bitset<8> bs3("10101");    // 用字符串初始化（二进制 00010101）
```

------

**重要操作**

```c++
//存取
bs[0] = 1;          // 设置最低位为 1
cout << bs[0];      // 访问最低位（返回 bool）

//设置 & 清空
bs.set();           // 全部置为 1
bs.set(3);          // 设置第 3 位为 1
bs.set(3, 0);       // 设置第 3 位为 0

bs.reset();         // 全部置为 0
bs.reset(2);        // 清除第 2 位
bs.flip();          // 所有位取反
bs.flip(1);         // 第 1 位取反

//统计
cout << bs.count();     // 统计 1 的个数
cout << bs.size();      // bitset 的总长度
cout << bs.any();       // 是否存在 1
cout << bs.none();      // 是否全 0

//转换
cout << bs.to_ulong();  // 转换成 unsigned long
cout << bs.to_ullong();// 转换成 unsigned long long
cout << bs.to_string(); // 转换成 string


//位运算
bitset<8> a("1010");
bitset<8> b("1100");

cout << (a & b) << endl;   // 按位与
cout << (a | b) << endl;   // 按位或
cout << (a ^ b) << endl;   // 按位异或
cout << (~a) << endl;      // 按位取反
cout << (a << 2) << endl;  // 左移
cout << (b >> 1) << endl;  // 右移

//直接输出
bitset<8> bs(42);
cout << bs << endl;   // 输出 00101010
```

## 4. 典型用途

- **子集/状态压缩**：存储集合的选择情况（比如动态规划、搜索）。
- **快速判重**：用作布隆过滤器的简单实现。
- **位运算模拟**：快速处理二进制数据（比 `vector<bool>` 更快）。

## Hash处理和function

```c++
# 模板处理
struct PairHash {
    template<typename T, typename U>
    size_t operator()(const pair<T, U>& p) const {
        auto h1 = hash<T>{}(p.first);
        auto h2 = hash<U>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};
unordered_map<pair<string, string>, int, PairHash> mp;
```

```c++
using HashPair = function<size_t(const pair<int, int>&)>;

auto my_hash = [](const pair<int, int>& p) {
    return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
};

unordered_map<pair<int, int>, int, HashPair> mp(0, my_hash);
```

## 动态function选择

```c++
function<bool(int, int)> cmp;
if (flag == 1) {
    cmp = [](int a, int b) { return a < b; };
} else {
    cmp = [](int a, int b) { return a > b; };
}
sort(v.begin(), v.end(), cmp);
```

# 输入输出处理

```
3
a 7
b 8
k 100
```

```c++
char q;
int t, n;
scanf("%d\n", &t);//加个换行符，可以吃掉换行符
while (t--) {
    scanf("%c %d\n", &q, &n); // 加个空格和回车符
}
```



# 方便函数

## 数字处理

```
//向上取整
ceil(x)
//向下取整
floor(x)
//四舍五入
round(x)
//截断小数
trunc(2.9)---->2.0
```

## 进制转换

```c++
//所有进制转10进制
string  s = "ff";
//意思是以16进制解析这个字符串
int x = stoi(s,nullptr,16);
cout<<x;
//255
```

```c++
//2转16
string bin = "11010111";
bitset<8> b(bin);
stringstream ss;
ss << std::hex << b.to_ulong(); // 转成十六进制
std::string hex = ss.str();

//16转2

string hex = "d7";
int value = std::stoi(hex, nullptr, 16); // 转成十进制整数
bitset<8> b(value);                 // 转成二进制
string ans = b.to_string();
```

## 数学

```c++
//求最大公约数,求两个数的最小公倍数，绝对值
gcd(a, b),lcm(a, b),abs(a)
    
// 求一个范围内的所有元素的总和
vector<int> numbers = {1, 2, 3, 4, 5};
int sum = accumulate(numbers.begin(), numbers.end(), 0); 
// sum 的值为 15

//生成序列的下一个字典序排列
//next_permutation
string s = "bac";
next_permutation(s.begin(), s.end()); 
//s 变为 "bca"
//常用于遍历一个序列的所有排列
string s2 = "abc";
do {
    std::cout << s2 << " ";
} while (next_permutation(s2.begin(), s2.end()));
//输出: abc acb bac bca cab cba

//nth_element 一般用于获取序列（有序无序都可以）第n小的数
int arr[10] = {8, 7, 4, 2, 1, 3, 9, 10, 5, 6};
// 让 arr + 6这个位置的数就绪，即将第7大的数放到arr[6]
nth_element(arr.begin(), arr + 6, arr.end()); 
// 即执行完后，arr + 6位置前的数都比他小，后面的数都不低于他
// 输出 6 5 4 2 1 3 7 8 10 9 

```

## 字符数字转换

```c++
//将字符串转换为整数
string s = "123";
int i = stoi(s); // i 的值为 123
//将数值类型转换为字符串
int i = 456;
string s = to_string(i); // s 的值为 "456"
```

## 字符串判断

```c++
//判断字符是否为字母 (a-z, A-Z)
char c = 'A';
bool is_alpha = isalpha(c); // is_alpha 为 true
//判断是否为小写字母
char c = 'a';
bool is_lower = islower(c); // is_lower 为 true
//判断是否为大写字母
char c = 'B';
bool is_upper = isupper(c); // is_upper 为 true
//判断是否为数字
char c = '7';
bool is_digit = isdigit(c); // is_digit 为 true
//判断是否为字母或数字
char c = 'Z';
bool is_alnum = isalnum(c); // is_alnum 为 true
```



# 组合数学

排列数

$$
P_{n}^{k}=\frac{n !}{(n-k) !}
$$


## 错位排列

正整数${1,2,...,n}$的一个排列叫错位排列是指该排列的整数i均不在第i位。例如$n=4$时，$(4 ,3 ,2 ,1)$是错位排列，而$(3, 2 ,4, 1)$不是，因为整数$2$仍在第$2$位。试统计错位排列的总数。

### 方法一

**记$\mathrm{D}_{\mathrm{n}}$为$n$阶错位排列个数，考虑元素$n$应该安排在何处。**

1. 对任意一个$n-1$阶错位排列，将任意一个元素与$n$对调，产生$n$阶错位排列。共产生$\mathrm{D}_{\mathrm{n}-1}(n-1)$个。
2. 对任意一个只有一个元素（元素i）在原位的n-1阶排列，将i与n对调，产生n阶错位排列。共产生$\mathrm{D}_{\mathrm{n}-2}(n-1)$个。
3. 其他情况均不能产生n阶错位排列。

**得出公式**
$$
D_{i}=\left\{\begin{array}{ll}
(i-1)\left(D_{i-1}+D_{i-2}\right) & (i>2) \\
0 & (i=1) \\
1 & (i=2)
\end{array}\right.
$$

### 方法二

记A为全体n阶排列数，Ai为i不在第i位的n阶排列数。

由容斥原理
$$
\begin{array}{l}
D_{n}=\left|A_{1} \cap A_{2} \cap \cdots \cap A_{n}\right|=|A|-\left|\overline{A_{1} \cap A_{2} \cap \cdots \cap A_{n}}\right| \\
=A|-| \overline{A_{1}} \cup \overline{A_{2}} \cup \cdots \cup \overline{A_{n}} \mid \\
=A\left|-\sum_{i=1}^{n}\right| \overline{A_{i}}\left|+\sum_{i \neq j}\right| \overline{A_{i}} \cap \overline{A_{j}}\left|-\sum_{i \neq j \neq k}\right| \overline{A_{i}} \cap \overline{A_{j}} \cap \overline{A_{k}}\left|+\cdots+(-1)^{n}\right| \overline{A_{1}} \cap \overline{A_{2}} \cap \cdots \overrightarrow{\cap A_{n}} \mid \\
=n !-C_{n}^{1}(n-1) !+C_{n}^{2}(n-2) !-C_{n}^{3}(n-3) !+\cdots+(-1)^{n} C_{n}^{n} 0 ! \\
=n !\left(1-\frac{1}{1 !}+\frac{1}{2 !}-\frac{1}{3 !}+\cdots+(-1)^{n} \frac{1}{n !}\right)
\end{array}
$$


### 代码实现

```c
const int N=1e5+1;
long long D(int n){
    long long dp[N]={0};
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}
```



## 圆不相邻选择数

n个位置的圆圈中取k个互不相邻位置的取法数

### 方法

用减法。固定某处为断开点，所求计数视为在$n-m$个非选中元素的空隙（包括两头）选m个插入的计数$C_{n-m+1}^{m}$，再排除两头同时插入的计数$C_{n-m+1}^{m-2}$

**得出公式**
$$
C_{n-m+1}^{m}-C_{n-m-1}^{m-2}=\frac{n}{n-m} C_{n-m}^{m} \quad(2 m \leq n, m \geq 2)
$$

## 卡特兰数

**定义**
$$
C(n)=\left\{\begin{array}{ll}
1 & (n=1) \\
\sum_{k=0}^{n-1} C(k) C(n-1-k) & (n>1)
\end{array}\right.
$$


### 代码实现

```c
long long catalan(int n) {
    if (n <= 1) {
        return 1;
    }
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}
```

遇到计数问题，前三个的序列是1，2，5，14，42一般就是卡特兰数

### 应用

- 括号匹配
- 进栈出栈序列
- 二叉树种类
- 元素数2n的集合不交叉划分
- 圆上2n点，连线不相交

#### 1、括号匹配问题

**n对括号有多少种匹配方式？**

$n$对括号相当于有$2n$个符号，$n$个左括号、$n$个右括号，可以设问题的解为$f(2n)$。第$0$个符号肯定为左括号，与之匹配的右括号必须为第$2i+1$字符。因为如果是第$2i$个字符，那么第0个字符与第$2i$个字符间包含奇数个字符，而奇数个字符是无法构成匹配的。

通过简单分析，$f(2n)$可以转化如下的递推式 $f(2n) = f(0)*f(2n-2) + f(2)*f(2n - 4) + ... + f(2n - 4)*f(2) + f(2n-2)*f(0)$

简单解释一下，$f(0) * f(2n-2)$表示第$0$个字符与第$1$个字符匹配，同时剩余字符分成两个部分，一部分为$0$个字符，另一部分为$2n-2$个字符，然后对这两部分求解。$f(2)*f(2n-4)$表示第$0$个字符与第$3$个字符匹配，同时剩余字符分成两个部分，一部分为$2$个字符，另一部分为$2n-4$个字符。依次类推。

假设$f(0) = 1$，计算一下开始几项，$f(2) = 1, f(4) = 2, f(6) = 5$。结合递归式，不难发现$f(2n)$ 等于$h(n)$

 

#### 2、进栈出栈问题

一个栈(无穷大)的进栈序列为$1,2,3,…,n$，有多少个不同的出栈序列?

 这个与加括号的很相似，进栈操作相当于是左括号，而出栈操作相当于右括号。n个数的进栈次序和出栈次序构成了一个含2n个数字的序列。第0个数字肯定是进栈的数，这个数相应的出栈的数一定是第2i+1个数。因为如果是2i，那么中间包含了奇数个数，这奇数个肯定无法构成进栈出栈序列。

 设问题的解为$f(2n)$， 那么$f(2n) = f(0)*f(2n-2) + f(2)*f(2n-4) + f(2n-2)*f(0)$,$f(0) * f(2n-2)$表示第$0$个数字进栈后立即出栈，此时这个数字的进栈与出栈间包含的数字个数为$0$，剩余为$2n-2$个数。$f(2)*f(2n-4)$表示第$0$个数字进栈与出栈间包含了$2$个数字，相当于$1, 2, 2, 1$，剩余为$2n-4$个数字。依次类推。

 假设$f(0) = 1$，计算一下开始几项，$f(2) = 1$, $f(4) = 2$, $f(6) = 5$。结合递归式，不难发现$f(2n)$ 等于$h(n)$



#### 3、二叉树的种类问题

$n$个节点构成的二叉树，共有多少种情形？

 可以这样考虑，根肯定会占用一个结点，那么剩余的n-1个结点可以有如下的分配方式

$T(0, n-1),T(1, n-2),...T(n-1, 0)$，设$T(i, j)$表示根的左子树含$i$个结点，右子树含$j$个结点。

 设问题的解为$f(n)$，那么

$f(n) = f(0)*f(n-1) + f(1)*f(n-2) + .......+ f(n-2)*f(1) + f(n-1)*f(0)$

假设$f(0) = 1$，那么$f(1) = 1,f(2) = 2, f(3) = 5。$结合递推式，不难发现$f(n)$等于$h(n)$。



#### 4、网格路径问题

对于一个n*n的正方形网格，每次我们能向右或者向上移动一格，那么从左下角到右上角的所有在副对角线右下方的路径总数为多少？

![img](https://img-blog.csdn.net/20140822102549925)



我们将一条水平边记为进栈,垂直边记为出栈，我们所要保证的就是前k步中水平边的个数不小于垂直边的个数，换句话说出栈的时候栈内一直有元素，所以从根本上说又回归到$Catalan$数了。

#### 5、凸多边形分割问题

求一个凸多边形区域划分成三角形区域的方法数？

![img](https://img-blog.csdn.net/20140822102334062)

 以凸多边形的一边为基，设这条边的2个顶点为A和B。从剩余顶点中选1个，可以将凸多边形分成三个部分，中间是一个三角形，左右两边分别是两个凸多边形，然后求解左右两个凸多边形。

设问题的解$f(n)$，其中n表示顶点数，那么$f(n) = f(2)*f(n-1) + f(3)*f(n-2) + ......f(n-2)*f(3) + f(n-1)*f(2)。f(2)*f(n-1)$表示三个相邻的顶点构成一个三角形，那么另外两个部分的顶点数分别为2和n-1。

设$f(2) = 1$，那么$f(3) = 1, f(4) = 2, f(5) = 5$。结合递推式，不难发现$f(n)$ 等于$h(n-2)$。

#### 6、集合划分问题

对于集合${1,2,3...2n}$的不交叉划分的数目为多少？

这里解释一下不交叉划分，我们对于集合$\left \{ a,b \right \} $和$\left \{ c,d \right \} $，假设他们组成了两个区间$[a,b]$和$[c,d]$，我们假设两个区间不重合，那么以下四种情况当做是不交叉的：$a<c<d<b,a<b<c<d,c<a<b<d$与$<d<a<b$，就是说两个区间可以包含或者相离，那么此时我们称集合$\left \{ a,b \right \} $和$\left \{ c,d \right \} $是不交叉的。

对于集合$\left \{ 1,2,3...2n \right \}$，将里面元素两两分为一子集，共$n$个，若任意两个子集都是不交叉的，那么我们称此时的这个划分为一个不交叉划分。此时不交叉的划分数就是我们的了，证明也很容易，我们将每个子集中较小的数用左括号代替，较大的用右括号代替，那么带入原来的1至2n的序列中就形成了合法括号问题，就是我们之前得到过的结论。例如我们的集合$\left \{1,2,3,4,5,6\right \}$的不交叉划分有五个: $\{\{1,2\},\{3,4\},\{5,6\}\},\{\{1,2\},\{3,6\},\{4,5\}\},\{\{1,4\},\{2,3\},\{5,6\}\},\{\{1,6\},\{2,3\},\{4,5\}\}$和$\{\{1,6\},\{2,5\},\{3,4\}\}$

#### 7、阶梯切分问题

求n层的阶梯切割为$n$个矩形的切法数

![img](https://img-blog.csdn.net/20140822102430412)



这个证明是怎么进行的呢？我们先绘制如下的一张图片，即n为5的时候的阶梯：

![img](https://img-blog.csdn.net/20140822102305125)



我们注意到每个切割出来的矩形都必需包括一块标示为*的小正方形，那么我们此时枚举每个*与#标示的两角作为矩形，剩下的两个小阶梯就是我们的两个更小的子问题了，于是我们的$C5 = C0 * C4 + C1 * C3 + C2 * C2 + C1 * C3 + C0 * C4$，注意到这里的式子就是我们前面的性质3,因此这就是我们所求的结果了。



#### 8、乘积重组问题

矩阵链乘： $P=a_{1}×a_{2}×a_{3}×……×a_{n}$，依据乘法结合律，不改变其顺序，只用括号表示成对的乘积，试问有几种括号化的方案？

 我们这样考虑，首先通过括号化，将P分成两个部分，然后分别对两个部分进行括号化。比如分成$(a_{1})×(a_{2}×a_{3}.....×a_{n})$，然后再对$a_{1}$和$a2×a3.....×an$分别括号化；又如分成$(a_{1}×a_{2})×(a_{3}.....×a_{n})$，然后再对$(a_{1}×a_{2})$和$(a_{3}.....×a_{n})$括号化。

 设n个矩阵的括号化方案的种数为$f(n)$，那么问题的解为

 $f(n) = f(1)*f(n-1) + f(2)*f(n-2) + f(3)*f(n-3) + f(n-1)*f(1)$。$f(1)*f(n-1)$表示分成$(a_{1})×(a_{2}×a_{3}.....×a_{n})$两部分，然后分别括号化。

 计算开始几项，$f(1) = 1, f(2) = 1, f(3) = 2, f(4) = 5$。结合递归式，不难发现$f(n)$等于$h(n-1)$。

   

#### 9、连线不想交问题

在圆上有$2n$个点，将这些点成对连接起来使得所得到的n条线段不相交的方法数？

我们这样考虑，以其中一个点为基点，编号为$0$，然后按顺时针方向将其他点依次编号。那么与编号为$0$相连点的编号一定是奇数，否则，这两个编号间含有奇数个点，势必会有个点被孤立，即在一条线段的两侧分别有一个孤立点，从而导致两线段相交。设选中的基点为$A$，与它连接的点为$B$，那么$A$和$B$将所有点分成两个部分，一部分位于$A,B$的左边，另一部分位于$A,B$的右边。然后分别对这两部分求解即可。

设问题的解$f(n)$，那么$f(n) = f(0)*f(n-2) + f(2)*f(n-4) + f(4)*f(n-6) + ......+f(n-4)*f(2) + f(n-2)*f(0)$。$f(0)\times f(n-2)$表示编号$0$的点与编号$1$的点相连，此时位于它们右边的点的个数为$0$，而位于它们左边的点为$2n-2$。依次类推。

$f(0) = 1, f(2) = 1, f(4) = 2$。结合递归式，不难发现$f(2n)$ 等于$h(n)$。



#### 10、高矮排队问题

$2n$个高矮不同的人,排成两排,每排必须是从矮到高排列,而且第二排比对应的第一排的人高,问排列方式有多少种?

先将$2n$个人从低到高排列，然后，用0表示对应的人在第一排,用$1$表示对应的人在第二排,那么含有$n$个$0,n$个$1$的序列,就对应一种方案. 
比如$00...011...1$就对应着 
第一排:$1 \quad  2 \quad  3 \quad ...n$
第二排:$n+1\quad n+2\quad n+3\quad ...2n$ 

而$010101...01$对应着

第一排:$1 \quad 3 \quad 5\quad ...2n-1$
第二排:$2 \quad 4 \quad 6\quad ...2n $

问题转换为,这样的满足条件的$01$序列有多少个
观察1的出现,我们考虑它能不能放在第二排,显然,在这个$1$之前出现的那些$0$和$1$对应的人 要么是在这个$1$左边,要么是在这个$1$前面。而即使前面$0$和$1$刚好配对，也一定要留出一个$0$在这个$1$前面，也就是要求之前的$0$的个数大于$1$的个数. 
如果把$0$看成入栈操作,$1$看成出栈操作,就是说给定$2n$个元素,合法的入栈出栈序列有多少个。这就是$Catalan$数,其通项是$C(2n, n)/(n+1)$. 

#### 11、格子填数问题

在一个$2\times n$的格子中填入$1$到$2n$这些数值使得每个格子内的数值都比其右边和上边的所有数值都小的情况数

这一题和上一题排队是一样的思路。

#### 12、门票找钱问题  

有$2n$个人排成一行进入剧场。入场费$5$元。其中只有$n$个人有一张$5$元钞票，另外$n$人只有$10$元钞票，剧院无其它钞票，问有多少中方法使得只要有$10$元的人买票，售票处就有$5$元的钞票找零？

可以将持$5$元买票视为进栈，那么持$10$元买票视为$5$元的出栈。这个问题就转化成了栈的出栈次序数。由应用三的分析直接得到结果，$f(2n)$ 等于$h(n)$。

### $Catalan$数的一个变形应用

上面第12小题的一个延伸：$n+m$个人排队买票，并且满足$n>= m$，票价为$5$元，其中$5$个人各手持一张$5$元钞票，$m$个人各手持一张$10$元钞票，除此之外大家身上没有任何其他的钱币，并且初始时候售票窗口没有钱，问有多少种排队的情况数能够让大家都买到票。

 这个题目是$Catalan$数的变形，不考虑人与人的差异，如果$m=n$的话那么就是我们初始的$Catalan$数问题，也就是将手持$5$元的人看成是入栈，手持$10$元的人看成是出栈，出栈序列的个数。

 这个题目区别就在于$n>m$的情况，此时我们仍然可以用原先的证明方法考虑，假设我们要的情况数是$D(n+m)$，无法让每个人都买到的情况数是$U(n + m)$，那么就有$D(n+m) + U(n +m) = C(m+n, n)$，此时我们求$U(n + m)$，我们假设最早买不到票的人编号是$k$，他手持的是$10$元并且售票处没有钱，那么将前k个人的钱从$5$元变成$10$元，从$10$元变成$5$元，这时候就有$n+1$个人手持$5$元，$m-1$个手持$10$元的，所以就得到$U(n + m) = C(n + m, n + 1)$，于是我们的结果就因此得到了，表达式是$D(n + m) = C_{n+m}^n - C_{n + m}^{n+1}$。



# 图和树

## 最短路径问题

### Dijkstra算法

使用广度优先搜索解决赋权有向图或无向图的单源点最短路径问题，最终得到一个最短路径树

```c++
#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX / 2;  // 防止溢出

vector<int> dijkstra(const vector<vector<int>>& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INF);    // 距离数组
    vector<bool> vis(n, false);  // 是否确定最短路

    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        // 1. 找到未访问的、距离最小的节点 u
        int u = -1, minDist = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break; // 说明剩下的点不可达
        vis[u] = true;

        // 2. 用 u 更新其他点的距离
        for (int v = 0; v < n; v++) {
            if (!vis[v] && graph[u][v] < INF) {
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
            }
        }
    }

    return dist;
}

int main() {
    // 邻接矩阵表示图
    vector<vector<int>> graph = {
        {0,   1,   4, INF, INF},
        {1,   0,   2,   7, INF},
        {4,   2,   0,   3,   5},
        {INF, 7,   3,   0,   1},
        {INF, INF, 5,   1,   0}
    };

    int src = 0;
    vector<int> dist = dijkstra(graph, src);

    cout << "从 " << src << " 出发的最短路:" << endl;
    for (int i = 0; i < dist.size(); i++) {
        cout << "到 " << i << " 的最短路 = " << dist[i] << endl;
    }

    return 0;
}

```

### Floyd算法

弗洛伊德算法是解决任意两点间的最短路径的一种算法，可以正确处理有向图或有向图或负权（但不可存在负权回路)的最短路径问题，同时也被用于计算有向图的传递闭包。

```c++
#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX / 2;  // 防止溢出

vector<vector<int>> floyd(vector<vector<int>> graph) {
    int n = graph.size();
    vector<vector<int>> dist = graph; // 初始化为原图的边权

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

int main() {
    // 邻接矩阵表示图
    vector<vector<int>> graph = {
        {0,   1,   4, INF, INF},
        {1,   0,   2,   7, INF},
        {4,   2,   0,   3,   5},
        {INF, 7,   3,   0,   1},
        {INF, INF, 5,   1,   0}
    };

    vector<vector<int>> dist = floyd(graph);

    cout << "任意两点的最短路矩阵：" << endl;
    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist.size(); j++) {
            if (dist[i][j] >= INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

```

## 最小生成树

### Kruskal算法

此算法可以称为“加边法”

```c++
#include<bits/stdc++.h>

using namespace std;
#define N 6

//样例邻接矩阵
int Edge[N][N] = {
        /*A   B   C   D   E   F*/
/*A*/   {0,   6,  1,  5,  0,  0},
/*B*/   {6,   0,  5,  0,  3,  0},
/*C*/   {1,   5,  0,  5,  6,  4},
/*D*/   {2,   0,  5,  0,  0,  2},
/*E*/   {0,   3,  6,  0,  0,  6},
/*F*/   {0,   0,  4,  2,  6,  0},
};
//记录边的权值，用于排序
struct Node{
    int a,b;
    int w;
    //重载
    bool operator < (const Node &C ) const {
        if (w == C.w)
            return w > C.w;
        return w < C.w;
    }
}a[30];
//使用并查集,作为辅助数据结构
int num[N];
int find(int x) { return x == num[x] ? x : num[x] = find(num[x]); }
void unionTwo(int a, int b){
    int a_father = find(a);
    int b_father = find(b);
    if(a_father != b_father){
        num[a_father] = b_father;
    }
}
int main(){
    //并查集初始化
    for (int i = 1; i <= N; i++)num[i] = i;
    int ind=0;
    //克鲁斯卡尔算法，最小生成树
    for(int i=0;i<N;i++){
        for (int j = i+1; j < N; ++j) {
            if(Edge[i][j]!=0){
                a[ind].a=i;
                a[ind].b=j;
                a[ind].w=Edge[i][j];
                ind++;
            }
        }
    }
    sort(a,a+ind);
    //cot记边数，sum记录最小生成树权值
    int cot=0,sum=0;
    //n-1条边,其实不用刻意判断n-1条边，当节点全部为一个集合时，不会执行if语句
    for(int i=0;i<ind;i++){
        int a_father = find(a[i].a);
        int b_father = find(a[i].b);
        if(a_father != b_father){
            num[a_father] = b_father;
            cot++;
            sum+=a[i].w;
        }
    }
//    for(int i=0;i<ind;i++){
//        printf("%c %c %d\n",a[i].a+'A',a[i].b+'A',a[i].w);
//    }

    printf("%d\n",sum);
    return 0;
}
```

### Prim算法

此算法可以称为“加点法”，每次迭代选择代价最小的边对应的点，加入到最小生成树中。算法从某一个顶点s开始，逐渐长大覆盖整个连通网的所有顶点。

## 并查集

```c++
#include <bits/stdc++.h>
using namespace std;
#define N 1001
int num[N];
int find(int x) { return x == num[x] ? x : num[x] = find(num[x]); }
int main(){
	//并查集初始化
	for (int i = 1; i <= n; i++)
			num[i] = i;
    cin>>k;
	for (int i = 0; i < k; i++){
		cin>>x>>y;
		int x = find(aa[j]);
		int y = find(bb[j]);
		num[x] = y;
	}
	return 0;
}

```

### 查找父节点

```c++
//快速写法
int find(int x){
	return x == num[x] ? x : num[x] = find(num[x]);
}
//标准写法
int find(int x){
	while(x!=num[x]){
		x=num[x];
	}	
	return x;
}
```

### 合并节点

```c++
//直接
int x = find(aa[j]);
int y = find(bb[j]);
num[x] = y;
//函数式
void unionTwo(int a, int b){
	int a_father = find(a);
	int b_father = find(b);
	if(a_father != b_father){
		num[a_father] = b_father;
	}
}
```

## 拓扑排序

在一个有向图中，对所有的节点进行排序，要求没有一个节点指向它前面的节点

**算法思路**

1. 先统计所有节点的入度，对于入度为0的节点就可以分离出来，然后把这个节点指向的节点的入度减一。
2. 一直做改操作，直到所有的节点都被分离出来。
3. 如果最后不存在入度为0的节点，那就说明有环，不存在拓扑排序，也就是很多题目的无解的情况

**图解**

![image-20210323150847736](https://gitee.com/lh253514942/img_bed/raw/master/img/image-20210323150847736.png)

**算法**

```c++
#include <bits/stdc++.h>
using namespace std;

// 拓扑排序（返回序列，如果有环返回空）
vector<int> topo_sort(int n, const vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);      // 入度
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    if (topo.size() != n) return {}; // 有环，返回空
    return topo;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    // 构建有向图
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> res = topo_sort(n, adj);
    if (res.empty()) {
        cout << "图中存在环，无法拓扑排序" << endl;
    } else {
        cout << "拓扑排序结果: ";
        for (int x : res) cout << x << " ";
        cout << endl;
    }

    return 0;
}

```



## 树形确定可用先中后序序列直接建树

```c++
//确定完全二叉树，由后序序列建树
#include <iostream>
using namespace std;
struct Node{
    int data;
    int l, r;
} node[31];
void postOrder(int d)
{
    if (node[d].l != 0)
        postOrder(node[d].l);
    if (node[d].r != 0)
        postOrder(node[d].r);
    cin >> node[d].data;
}
int main()
{
    int N;
    cin >> N;
    //建立完全二叉树的联系
    for (int i = 1; i <= N; ++i){
        if (i * 2 <= N)
            node[i].l = i * 2;
        if (i * 2 + 1 <= N)
            node[i].r = i * 2 + 1;
    }
    //后序建立二叉树，因为此时树的形状已经确定，
    // 只差节点的值没有给树，所以后序遍历同时，节点赋值
    postOrder(1);
    //输出
    cout << node[1].data;
    for (int i = 2; i <= N; ++i)
        cout << " " << node[i].data;
}

```



# 数论

## 快速幂

```c++
typedef long long ll;
ll ksm(ll a, ll n, ll mod) {	//a为底数，n为指数，mod为模数
	ll ans = 1;
	while (n) {
		if (n & 1)
			ans = ans * a % mod;	//判断n的最后一位是不是1
		a = a * a % mod; //将a自乘
		n >>= 1;	//舍去n的最后一位
	}
	return ans;
}
```



## 素数

### 素数判断

##### 6n附近判断

```c++
bool is_prime(unsigned long long n) { //quick
	unsigned long long stop = n / 6 + 1, Tstop = sqrt(n) + 5;
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11) {
		return 1;
	}
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n == 1) {
		return 0;
	}
	for (unsigned long long i = 1; i <= stop; i++) {
		if (i * 6 >= Tstop) {break;}
		if ((n % (i * 6 + 1) == 0) || (n % (i * 6 + 5) == 0)) {
			return 0;
		}
	}
	return 1;
}

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int limit = sqrt(n);
    for (int i = 5; i <= limit; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
```

## 欧拉函数

欧拉函数$φ(n)$：$\left \{1, 2, …, n  \right \}$中与$n$互素的数的个数。

$φ(1)=1$

$φ(2)=|\left \{1\right \}|=1$

$ φ(6)=|\left \{1,5 \right \}|=2$

$ φ(8)=|\left \{1,3,5,7 \right \}|=4$



注意：$0$与$n$不互素，有公因子$n$。

欧拉函数$φ(n)$也可说是$\left \{1, 2, …, n-1  \right \}$中与$n$互素的数的个数

### 性质

1. 素数$n$的欧拉函数是$φ(n)= n-1$
2. 若$n$是素数$p$的$k$次幂，
   -  $φ(n)=p^k-p^{k-1}=(p-1)p^{k-1}$
   - ![image-20210313200340944](https://gitee.com/lh253514942/img_bed/raw/master/img/20210313200348.png)
3. 若$m，n$互素， $φ(mn)= φ(m) φ(n)$

### 推导

![image-20210313200547631](https://gitee.com/lh253514942/img_bed/raw/master/img/20210313200547.png)

![image-20210313200619025](https://gitee.com/lh253514942/img_bed/raw/master/img/20210313200619.png)

### 代码

```c++
int phi1(int n) {	// 欧拉函数phi(n)
	int res = 1;
	int p = 2;
	do {
		if (n % p == 0) {
			res *= (p - 1);
			n /= p;
			while (n % p == 0)
				n /= p, res *= p;
		}
		p++;
	} while (p * p <= n);
	if (n > 1)
		res *= (n - 1);
	return res;
}

int phi2(int n) {	// 欧拉函数phi(n)
	int res = n;
	int p = 2;
	do {
		if (n % p == 0) {
			res -= res / p;
			while (n % p == 0)
				n /= p;
		}
		p++;
	} while (p * p <= n);
	if (n > 1)
		res -= res / n;
	return res;
}
int phi3(int n, int p) {
	// 主函数调用phi3(n, 2);
	if (n == 1)
		return 1;
	while (n % p)
		p++;
	n /= p;
	return ((n % p) ? (p - 1) : p) * phi3(n, p);
}

```

## 欧拉筛

### 原理

![image-20210313200703597](https://gitee.com/lh253514942/img_bed/raw/master/img/20210313200703.png)

### 代码

```c++
int phi[NMAX];
void getPhi(int n) {
	for (int i = 1; i <= n; i++)
		phi[i] = i;
	for (int i = 2; i <= n; i++) {
		if (phi[i] == i)	// 当i是素数时 
			// 以i为素因子者, phi累乘(1-1/i) 
			for (int j = i; j <= n; j += i)
				phi[j] = phi[j] / i * (i - 1);
	}
}

```

### 欧拉函数前缀和

问题：求$φ(1)+ φ(2)+ φ(3)+...+φ(n)$

使用欧拉筛，然后求和

### 欧拉降幂

![image-20210313201320292](https://gitee.com/lh253514942/img_bed/raw/master/img/20210313201320.png)

### 积性函数

![image-20210313201344392](https://gitee.com/lh253514942/img_bed/raw/master/img/20210313201344.png)

若任意正整数，则称为完全积性函数

### 杜教筛

# 进制转换

## C指定格式输出

```c++
printf("%05o\n",35);    //按八进制格式输出，保留5位高位补零
printf("%03d\n",35);    //按十进制格式输出，保留3位高位补零
printf("%05x\n",35);    //按十六进制格式输出，保留5位高位补零
```

## 字符串到10进制数

```c++
int Atoi(string s,int radix){    //s是给定的radix进制字符串
	int ans=0;
	for(int i=0;i<s.size();i++){
		char t=s[i];
		if(t>='0'&&t<='9') ans=ans*radix+t-'0';
		else ans=ans*radix+t-'a'+10;
	}
		return ans;
}
```

## 10进制到n进制

```c++
string intToA(int n,int radix)    //n是待转数字，radix是指定的进制
{
	string ans="";
	do{
		int t=n%radix;
		if(t>=0&&t<=9)	ans+=t+'0';
		else ans+=t-10+'a';
		n/=radix;
	}while(n!=0);	//使用do{}while（）以防止输入为0的情况
	reverse(ans.begin(),ans.end());
	return ans;	
}
```



# 杂项小技术

## 幂集遍历

可用位运算 000-111

```c++
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};
```



## 优先队列

```c++
//从大到小
priority_queue<int> q;
priority_queue<int,vector<int>,less<int>> q;
//从小到大
priority_queue<int,vector<int>,greater<int>> q;
//结构体
struct fruit{
    string name;
    string price;
    friend bool operator < (fruit a,fruit b){
    	//与sort中的cmp有差别，return <返回的是大顶堆
        return a.price < b.price;
    }
};
//定义
priority_queue<fruit> q;

//另一种写法：（定义结构体cmp，去掉friend，将<改为()）
struct cmp{
    bool operator () (fruit a,fruit b){
        return a.price < b.price;
    }
};
//定义
priority_queue<fruit,vector<fruit>,cmp> q;
```

# 厚黑学

## 竞赛厚黑学之一：规模-算法谱

算法竞赛时，充分利用、合理利用竞赛规则，但没有违反规则，为问题寻找算法方案，提高AC的机会，此类行为合法，——竞赛厚黑学也。

竞赛题目的命题肯定会给出问题规模，而且一般会让问题规模在命题者预知算法下达到上限，这一点可以利用起来为问题的算法选择提供初步方案。如下图所示的问题规模-算法谱，粗略标出了每种算法能解决的问题规模范围。大致来看，暴力枚举的算法能力最弱，解析式是最快的“算法”，O(1)时间解决任意问题。

这张图谱可以反着用。一是从规模倒看哪几类算法可用，数据规模提示了候选算法。二是已知数据的规模，你知道哪些算法肯定不能用。比如数据规模达104，不可能DFS、BFS。

![img](https://gitee.com/lh253514942/img_bed/raw/master/img/clip_image002.gif)

# 单调栈

在单调栈基础题中，经常需要类似这种的解题思路：在 *O*(*n*) 的时间复杂度内求出数组中各个元素右侧第一个更大的元素及其下标，然后一并得到其他信息。

https://leetcode.cn/problems/daily-temperatures/?envType=problem-list-v2&envId=2cktkvj

```c++
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> ans(temperatures.size(),0);
    stack<int> s;
    for(int i=0;i<temperatures.size();i++){
        int x = temperatures[i];
        //空 压栈
        if(s.empty()){
            s.push(i);
        }
        //递减 压栈
        else if(x<temperatures[s.top()]){
            s.push(i);
        }
        //递增了 进行处理
        else{
            //循环与顶比较，如果是递增则下标差就是天数
            while(!s.empty()&&x>temperatures[s.top()]){
                ans[s.top()]=i-s.top();
                s.pop();
            }
            //当前压栈
            s.push(i);
        }
    }
    //末尾递减处理
    while(!s.empty()){
        ans[s.top()]=0;
        s.pop();
    }
    return ans;
}
```

# 前缀树

前缀树（Trie，发音同"try"）是一种专门用于处理字符串搜索的树形数据结构，特别适合实现自动补全、拼写检查、IP路由等功能。

```C++
//前缀树类
class Trie {
private:
    //一般26个空的指针数组
    vector<Trie*> children;
    //是否是结尾
    bool isEnd;
	
    //前缀搜索
    Trie* searchPrefix(string prefix) {
        //根节点
        Trie* node = this;
        //遍历搜索数组
        for (char ch : prefix) {
            //获得下一个字符下标
            ch -= 'a';
            //如果存在则是非空
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            //递归
            node = node->children[ch];
        }
        return node;
    }

public:
    //构造函数，26个空指针列表
    Trie() : children(26), isEnd(false) {}
	//插入函数
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            //为下一个字母index创建node
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

```

# 线段树

- 多用于解决
  1. 多次区间查询
  2. 频繁更新
  3. 频繁查询
  4. 更新查询交错来临
- 典型应用
  - 任意区间的最大值、最小值、总和、平均值等统计量包括$RMQ (Range minimum query)$
  - 任意区间的被覆盖总长度
  - 任意区间的被覆盖重数的统计量
  - 矩形并的总面积、总周长
  - 子树的查询

### 导例

**问题**：直线上分布一系列的整数格点$1，2，…，n$，有$m$个整数线段$[a_i,b_i]（1\le a_i\le b_i\le n,i=1...m）$，有q个询问，问区间$[s_j,t_j]$分别被线段覆盖的总长度，即$[a_i,b_i]$的并集落在$[s_j,t_j]$范围的整数格点数。

例如：$n=12$，$m=5$，$m$个线段是$[1,5]， [4,6]， [9,9]， [1,2]， [8,10]$，

则$[1,12]$被覆盖总长度是$9$，而$[2,9]$被覆盖总长度为$7$。

![image-20210310194113768](D:\BaiduSyncdisk\md\.image\20210310194113.png)

**简单染色法**

1. 根据直线的最大坐标范围，开一个大数组，初始化为$0$；
2. 然后对每一线段$[a_i,b_i]$，将包含的整数染色为$1$；
3. 最后统计区间中$1$的个数。

**线段树存储法**

![image-20210310194631441](D:\BaiduSyncdisk\md\.image\20210310194631.png)

**思路**

首先在附加数据域设一个cover标记来跟踪一个区间是否被全覆盖，也可再设一个length跟踪覆盖长度（本例不设）。

### Node

```c++
struct Node {
    int left, right;
    int cover;  // 标记， 1表示被全覆盖
};
//定义
struct Node ST[NMAX*4];
```

然后实现三个模块：建立、更新、查询。

### 建立

建立线段树，顺便将cover初值置0。

```c++
void Build(int i, int l, int r){	
    //建立线段树，主程序调用语句：Build(1, 1, n)
	ST[i].left = l;
	ST[i].right = r;
    //cover置零
	ST[i].cover = 0;
	if (l == r)
		return;
	int mid = (l+r) / 2;
	Build(i*2, l, mid);
	Build(i*2+1, mid+1, r);
}
```

### 更新

根据每个线段$[a_i,b_i]$对线段树进行更新，记录覆盖情况。

```c++
void Update(int i, int a, int b){	
    // 更新线段树，main调用语句：Update(1, ai, bi) 
	if (a <= ST[i].left && b >= ST[i].right) {
		ST[i].cover = 1;
		return;
	}
	int mid = (ST[i].left + ST[i].right) / 2;
	if (a <= mid)
		Update(i*2, a, b);
	if (b > mid)
		Update(i*2+1, a, b);
}
```

### 查询

1. **如果这个区间被完全包括在目标区间里面，直接返回这个区间的值**
2. **如果这个区间的左儿子和目标区间有交集**，**那么搜索左儿子**
3. **如果这个区间的右儿子和目标区间有交集**，**那么搜索右儿子****

对任意区间的查询，由它的拼接元线段和标记返回查询结果。

```c++
int Query(int i, int s, int t){	
	// 查询线段树，main调用语句：Query(1, sj, tj) 
	if (ST[i].cover == 1)
		return t - s + 1;
	if (ST[i].right == ST[i].left)
		return 0;
	int mid = (ST[i].left + ST[i].right) / 2;
	int ans = 0;
	if (s <= mid)
		ans += Query(i*2, s, min(t, mid));
	if (t > mid)
		ans += Query(i*2+1, max(s, mid+1), t);
	return ans;
}
```

### 全部代码

```c++
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
#define ll long long
struct Node{
    ll left,right;
    //存储权值
    ll sum;
    ll lz=0;
};
struct Node N[400002];
ll w[400002];

//将lazy标志向下压
void push_down(ll i){
    //左右儿子分别加上父亲的lz
    N[i * 2].lz += N[i].lz;
    N[i * 2 + 1].lz += N[i].lz;
    //左右分别求和加起来
    N[i * 2].sum += N[i].lz * (N[i * 2].right - N[i * 2].left + 1);
    N[i * 2 + 1].sum += N[i].lz * (N[i * 2 + 1].right - N[i * 2 + 1].left+1);
    //父亲lz归零
    N[i].lz = 0;
}
//线段树创建
void build(ll i ,ll l,ll r){
    N[i].left=l;
    N[i].right=r;
    if(l==r){
        //赋予权值
        N[i].sum = w[l];
        return;
    }
    ll mid = (l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    N[i].sum = N[i*2].sum+N[i*2+1].sum;
    return;
}

//区间修改，单点修改可以归结为特殊情况
void add(ll i,ll l,ll r,ll k){
    //如果当前区间被完全覆盖在目标区间里，讲这个区间的sum+k*(N[i].r-N[i].l+1)
    if(N[i].right<=r && N[i].left>=l){
        //这个区间的每个节点加k,总和为k*(r-l+1)
        N[i].sum+=k*(N[i].right-N[i].left+1);
        //表记这个节点是懒节点；
        N[i].lz+=k;//记录lazytage
        return;
    }
    //向下传递懒节点
    push_down(i);
    if(N[i*2].right>=l)
        add(i*2,l,r,k);
    if(N[i*2+1].left<=r)
        add(i*2+1,l,r,k);
    N[i].sum=N[i*2].sum+N[i*2+1].sum;
    return ;
}
//区间查询，单点查询为特殊情况
ll CalSum(ll i,ll x, ll y) {
    //如果当前区间在目标区间内
    if(N[i].left>=x&&N[i].right<=y){
        return N[i].sum;
    }
    //如果毫不相干
    if(N[i].left>y||N[i].right<x){
        return 0;
    }
    //如果有懒标记，节点下压
    push_down(i);
    ll s=0;
    //左儿子有交集
    if(N[i*2].right>=x) s+=CalSum(i*2,x,y);
    //右儿子有交集
    if(N[i*2+1].left<=y) s+=CalSum(i*2+1,x,y);
    return s;
}

int main() {

    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    build(1,1,n);

    while(m--){
        ll flag,x,y,k;
        cin>>flag;
        if(flag==1){
            cin>>x>>y>>k;
            add(1,x,y,k);
        }else{
            cin>>x>>y;
            printf("%lld\n",CalSum(1,x,y));
        }
    }
}
```

# 位运算

```c++
//统计1有几个的函数
__builtin_popcount(z)
```

## 基本的位运算符

### 1. **按位与 (AND) - `&`**

cpp

```
int a = 5;    // 二进制: 0101
int b = 3;    // 二进制: 0011
int result = a & b;  // 0001 → 1
```

**用途**：提取特定位、掩码操作、判断奇偶性

### 2. **按位或 (OR) - `|`**

cpp

```
int a = 5;    // 0101
int b = 3;    // 0011
int result = a | b;  // 0111 → 7
```

**用途**：设置特定位、组合标志位

### 3. **按位异或 (XOR) - `^`**

cpp

```
int a = 5;    // 0101
int b = 3;    // 0011
int result = a ^ b;  // 0110 → 6
```

**特性**：相同为0，不同为1
**用途**：交换变量、找唯一数、加密

### 4. **按位取反 (NOT) - `~`**

cpp

```
int a = 5;    // 0000 0101
int result = ~a;     // 1111 1010 → -6 (补码表示)
```

**注意**：结果取决于数据类型和位数

### 5. **左移 (Left Shift) - `<<`**

cpp

```
int a = 5;    // 0101
int result = a << 2; // 010100 → 20
```

**效果**：相当于乘以2的n次方

### 6. **右移 (Right Shift) - `>>`**

cpp

```
int a = 20;   // 10100
int result = a >> 2; // 00101 → 5
```

**效果**：相当于除以2的n次方（向下取整）

## 实用技巧和示例

### 1. 判断奇偶性

cpp

```
bool isEven(int n) {
    return (n & 1) == 0;  // 最后一位为0则是偶数
}
```

### 2. 交换两个数（不用临时变量）

cpp

```
void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;  // b = (a^b)^b = a
    a = a ^ b;  // a = (a^b)^a = b
}
```

### 3. 检查第n位是否为1

cpp

```
bool isBitSet(int num, int pos) {
    return (num & (1 << pos)) != 0;
}
```

### 4. 设置第n位为1

cpp

```
int setBit(int num, int pos) {
    return num | (1 << pos);
}
```

### 5. 清除第n位（设为0）

cpp

```
int clearBit(int num, int pos) {
    return num & ~(1 << pos);
}
```

### 6. 切换第n位（0变1，1变0）

cpp

```
int toggleBit(int num, int pos) {
    return num ^ (1 << pos);
}
```

## 实际应用场景

### 1. 权限系统

cpp

```
enum Permissions {
    READ = 1 << 0,    // 0001
    WRITE = 1 << 1,   // 0010
    EXECUTE = 1 << 2  // 0100
};

int userPermissions = READ | WRITE;  // 0011

// 检查权限
bool canRead = (userPermissions & READ) != 0;
bool canExecute = (userPermissions & EXECUTE) != 0;

// 添加权限
userPermissions |= EXECUTE;

// 移除权限
userPermissions &= ~WRITE;
```

### 2. 找唯一出现的数字

cpp

```
// 数组中只有一个数字出现一次，其他都出现两次
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // 相同的数字异或会抵消
    }
    return result;
}
```

### 3. 计算二进制中1的个数

cpp

```
int countOnes(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // 每次清除最右边的1
        count++;
    }
    return count;
}
```

### 4. 判断是否是2的幂

cpp

```
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

## 注意事项

1. **运算符优先级**：位运算符优先级较低，建议多用括号

   cpp

   ```
   int result = (a & b) == c;  // 正确
   int result = a & b == c;    // 错误！== 优先级高于 &
   ```

2. **符号位问题**：右移有符号数时，高位补符号位（算术右移）

   cpp

   ```
   int a = -8;      // 1111 1000
   int b = a >> 2;  // 1111 1110 → -2
   ```

3. **无符号右移**：使用无符号数避免符号位问题

   cpp

   ```
   unsigned int a = -8;  // 4294967288
   unsigned int b = a >> 2;  // 1073741822
   ```

4. **移位范围**：移位位数应在0到数据类型位数-1之间

位运算虽然强大，但代码可读性较差，建议适当添加注释说明意图。



# 先排队再插队

[406. 根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/)



# DP动态规划

可以划分为小问题，寻找递推函数

## 单词拆分

[leetcode139](https://leetcode.cn/problems/word-break/description/?envType=problem-list-v2&envId=2cktkvj)

![image-20250830200443438](D:\BaiduSyncdisk\md\.image\image-20250830200443438.png)

0代表不可能，1代表可能

dp[0]=1，开头为空串，找到worddict中匹配的则

dp[i] = dp[j]+worddict

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();
        vector<bool> dp(sz + 1, 0);
        dp[0] = true;
        for (int i = 0; i < sz; ++i) {
        	//真的才需要继续检查
            if (!dp[i]) continue
            //直接遍历字典
            for (int j = 0; j < wordDict.size(); ++j) {
                //截取片段是否相等
                int len = wordDict[j].size();
                string str = s.substr(i,len);
                if (str == wordDict[j]) {
                    dp[i + len] = true;
                }
            }
        }
        return dp[sz];
    }
};
```

## 零钱兑换

[322](https://leetcode.cn/problems/coin-change/description/?envType=problem-list-v2&envId=2cktkvj)

![image-20250830202331933](D:\BaiduSyncdisk\md\.image\image-20250830202331933.png)

dp[i] 金额i最少的硬币个数 -1不可能

开始 coins中的都为1

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //特殊要求特殊处理
        if(amount==0)return 0;
        vector<int> dp(amount+1,-1);
        //开始处理
        for(int i:coins){
            if(i<=amount)
                dp[i]=1;
        }
        //dp进行
        for(int i=0;i<=amount;i++){
            for(int coin:coins){
                int index = i-coin;
                //下标不能越界
                if(index>=1){
                    //如果index可以达成
                    if(dp[index]>0){
                        //选择最优记得
                        if(dp[i]>0){
                            dp[i] = min(dp[i],dp[index]+1);
                        }
                        else{
                            dp[i]=dp[index]+1;
                        }
                    }
                    
                }
            }
        }
        return dp[amount];
    }
};
```

## 0-1背包问题

[416](https://leetcode.cn/problems/partition-equal-subset-sum/solutions/442320/fen-ge-deng-he-zi-ji-by-leetcode-solution/?envType=problem-list-v2&envId=2cktkvj)

## 树形DP

[337. 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/)

f(i) 选中节点i的最大值 = g(l)+g(r);

g(i) 不选中节点i的最大值 = max(g(l),f(r))+max(g(r),f(r))

注意树形DP的从下自上的格式

```C++
class Solution {
public:
    unordered_map <TreeNode*, int> f, g;

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        //移到最尾巴，从下向上
        dfs(node->left);
        dfs(node->right);
        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }

    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};
```

## 编辑距离

[72. 编辑距离](https://leetcode.cn/problems/edit-distance/)

![image-20250901135010316](D:\BaiduSyncdisk\md\.image\image-20250901135010316.png)

`D[i][j]` 表示 `A` 的前 `i` 个字母和 `B` 的前 `j` 个字母之间的编辑距离。



```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP 数组
        vector<vector<int>> D(n + 1, vector<int>(m + 1));

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                //情况1，2 插入一个字符
                int left = D[i - 1][j] + 1;
                int down = D[i][j - 1] + 1;
                //情况3  相同不用插入，不相同修改一个
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                D[i][j] = min(left, min(down, left_down));

            }
        }
        return D[n][m];
    }
};

```



# 二叉树

## 求深度

```c++
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
    	return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}
```



## 层序遍历

```c++
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        // 这里一定要使用固定大小size，不要使用que.size()
        //因为que.size是不断变化的
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}
```

## 中序后序构造二叉树

后序尾巴是根，递归构造即可

![image-20250831170329392](D:\BaiduSyncdisk\md\.image\image-20250831170329392.png)

```c++
class Solution {
private:
    TreeNode* traversal (vector<int>& inorder, 
                         vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;

        // 后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // 叶子节点
        if (postorder.size() == 1) return root;

        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size();
             	delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), 
                                inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + 
                                 delimiterIndex + 1, inorder.end() );

        // postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(),
                                  postorder.begin() +
                                  leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() +
                                   leftInorder.size(), 
                                   postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, 
                        vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};
```



# 双指针法

## 移除元素

[27. 移除元素](https://leetcode.cn/problems/remove-element/)

O(n)移除特定元素，前后指针

# 回溯

## 全排列

```c++
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};
```



## 重新安排行程

https://leetcode.cn/problems/reconstruct-itinerary/description/

记住这个unorder_map<string,multiset<string>> g的用法

```c++
class Solution {
public:
    unordered_map<string, multiset<string>> g; // 出发点 -> 有序目的地集合
    vector<string> route;

    void dfs(const string& u) {
        while(!g[u].empty()) {
            auto it = g[u].begin(); // 取字典序最小的目的地
            string v = *it;
            g[u].erase(it);         // 用掉这条边
            dfs(v);
        }
        route.push_back(u); // 回溯时加入路径
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 建图
        for(auto &t : tickets) {
            g[t[0]].insert(t[1]);
        }

        dfs("JFK");
        reverse(route.begin(), route.end()); // 反转得到正序
        return route;
    }
};

```



## N皇后

```C++
class Solution {
public:
    vector<vector<string>> ans;
    int nn;
	//判断函数，行回溯，优化行的判断
    bool jud(int row, int col, vector<string>& M) {
        for(int i = 0; i < row; i++) {
            if(M[i][col] == 'Q') return false;
            int d = row - i;
            if(col - d >= 0 && M[i][col - d] == 'Q') return false;
            if(col + d < nn && M[i][col + d] == 'Q') return false;
        }
        return true;
    }
	//搜索函数
    void dfs(int row, vector<string>& M) {
        if(row == nn) {
            ans.push_back(M);
            return;
        }
        for(int col = 0; col < nn; col++) {
            if(jud(row, col, M)) {
                M[row][col] = 'Q';
                dfs(row + 1, M);
                M[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        nn = n;
        vector<string> M(n, string(n, '.')); 
        dfs(0, M);
        return ans;
    }
};

```

## 最大独立集权值问题

https://kamacoder.com/problempage.php?pid=1345

265.亲和调度任务组

###### 题目描述

调度器上有一组待调度的任务(Job)，大部分任务之间存在亲和关系，需要优先把具有亲和关系的任务调度到同一个核上面，不亲和的任务不能运行在同一个核上面； 现在给定一组待调度的任务（任务编号和任务执行时间），同时会给出任务之间不存在亲和关系的列表（未给出的默认是亲和关系）。请设计一个调度器，按照如下要求：

1. 找出一组包含亲和任务数量最多的亲和调度任务组；
2. 如果规则1有多个解，给出所有任务执行时间之和最小的。 并输出该亲和调度任务组的所有任务的执行时间之和。

亲和调度任务组定义：一组可以在同一核上面执行的亲和任务集合

###### 输入描述

首行是一个整数jobNum，表示任务数量，任务编号[1, jobNum]，取值范围 [1,30]；

第二行jobNum个整数，表示每个任务的执行时间；

第三行是一个整数mutexNum，表示不存在亲和关系的列表个数；

接下来mutexNum行，每一行表示1对不亲和的任务编号，任务编号范围[1, jobNum]。

###### 输出描述

一个整数，表示所有任务的最短执行时间。

###### 输入示例

```
3 
2 3 10 
1 
1 2
```

###### 输出示例

```
12
```



回溯+剪枝

```c++
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> cost;
bool conflict[31][31];

int bestSize = 0, bestSum = INT_MAX;

void dfs(int idx, vector<int>& chosen, int curSize, int curSum) {
    if (idx > n) {
        if (curSize > bestSize || (curSize == bestSize && curSum < bestSum)) {
            bestSize = curSize;
            bestSum = curSum;
        }
        return;
    }

    // 剪枝：剩下的点全选也不可能超过最佳
    if (curSize + (n - idx + 1) < bestSize) return;

    // 尝试选 idx
    bool ok = true;
    for (int v : chosen) {
        if (conflict[v][idx]) { ok = false; break; }
    }
    if (ok) {
        chosen.push_back(idx);
        dfs(idx+1, chosen, curSize+1, curSum+cost[idx]);
        chosen.pop_back();
    }

    // 不选 idx
    dfs(idx+1, chosen, curSize, curSum);
}

int main() {
    cin >> n;
    cost.resize(n+1);
    for (int i=1; i<=n; i++) cin >> cost[i];
    int m; cin >> m;
    memset(conflict,0,sizeof(conflict));
    for (int i=0;i<m;i++) {
        int a,b; cin >> a >> b;
        conflict[a][b]=conflict[b][a]=true;
    }
    vector<int> chosen;
    dfs(1, chosen, 0, 0);
    cout << bestSum << endl;
}

```

# 拓扑排序

```c++
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;

        // 构建邻接表 + 入度表
        for (auto &p : prerequisites) {
            int a = p[0], b = p[1];
            graph[b].push_back(a);
            indegree[a]++;
        }

        // 队列存放所有入度为 0 的节点
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // BFS 拓扑排序
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            ans.push_back(cur);
            for (int nxt : graph[cur]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) q.push(nxt);
            }
        }

        // 如果所有课都能学完，返回顺序，否则返回空
        if (ans.size() == numCourses) return ans;
        return {};
    }
};

```

