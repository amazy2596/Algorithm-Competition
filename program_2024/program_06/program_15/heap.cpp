#include<iostream>
using namespace std;

// 定义堆数组的常量大小
const int N = 2e5 + 5;
int heap[N], n;

// 通过上移操作保持堆性质
void up(int p)
{
    while (p > 1)
    {
        // 如果当前元素大于其父节点，则交换它们
        if (heap[p] > heap[p / 2])
        {
            swap(heap[p], heap[p / 2]);
            p /= 2; // 移动到父节点
        }
        else 
            break;
    }
}

// 向堆中添加新元素
void push(int val)
{
    heap[++n] = val; // 将新元素插入堆的末尾
    up(n); // 通过上移操作保持堆性质
}

// 通过下移操作保持堆性质
void down(int p)
{
    int s = p * 2; // 左子节点的索引
    while (s <= n)
    {
        // 找到更大的子节点
        if (s < n && heap[s] < heap[s + 1])
            s++;
        // 如果当前元素小于更大的子节点，则交换它们
        if (heap[p] < heap[s])
        {
            swap(heap[p], heap[s]);
            p = s; // 移动到子节点
            s *= 2; // 更新子节点索引
        }
        else 
            break;
    }
}

// 移除堆顶元素
void pop()
{
    heap[1] = heap[n--]; // 用最后一个元素替换堆顶元素
    down(1); // 通过下移操作保持堆性质
}

// 移除堆中指定索引的元素
void remove(int idx)
{
    heap[idx] = heap[n--]; // 用最后一个元素替换索引为 idx 的元素
    up(idx); // 通过上移操作保持堆性质
    down(idx); // 通过下移操作保持堆性质
}

// 获取堆顶元素
int top()
{
    return heap[1];
}

// 获取堆的大小
int size()
{
    return n;
}

// 检查堆是否为空
bool isEmpty()
{
    return n;
}

int main()
{
    // 向堆中插入10个元素
    for (int i = 0; i < 10; i++)
    {
        int val;
        cin >> val;
        push(val);
    }
    // 输出堆顶元素
    cout << top() << "\n";
    // 移除堆顶元素
    pop();
    // 输出新的堆顶元素
    cout << top() << "\n";
    // 移除最后一个元素
    remove(n);
    // 输出并移除堆中的所有剩余元素
    for (int i = 0; i < n; i++)
    {
        cout << top() << " ";
        pop();
    }
    return 0;
}
