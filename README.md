# Leetcode-coding-2025
## Documentation

1.hash

#include <unordered_map> 
    
    **键值对的hash映射，键唯一** 
        #需要声明key和value的数据类型 
    **插入和更新** 
        #[]便捷操作符，插入和创建，没有则创建，有则更新 
        #.insert(), 插入操作，接受std::pair,如果有此键，无任何操作 、
    **访问元素** 
        #[]便捷操作符，访问元素，直接通过key访问对应的value，若不存在则自动插入一个具有默认构造值的元素
        #.at(),若没有该键，则报错 #删除元素 #.erase()通过键，删除对应的键值对 
    **常用操作** 
        #.find(), 查找键，返回指向元素的迭代器 
        #.count(), 查找键，返回0或1 
        #.size(), 返回容器元素 
        #.empty(), 容器是否为空 
        #.clear(), 清空容器 
#include <unordered_set>

    **唯一元素的hash集合** 
        #适用于检查元素是否在集合中 
    **声明** 
        #需指明数据类型 
    **基本操作** 
        #.insert(), 插入，元素已存在，不会操作 
        #.find(), 查找键，返回指向元素的迭代器 
        #.count(), 查找键，返回0或1 
        #.erase(), 删除 #.size(), 返回容器大小 
        #.empty(),容器是否为空 
        #.clear(), 清空容器 
hash 适用于快速查找，插入和删除，且不关心元素顺序

2.double pointer

    **核心思想**
        在一个‘数据结构’（最常见的是数组或链表）上设置两个指针，然后根据‘特定规则’移动这两个指针，直到它们满足某个条件或相遇为止。可以将一些需要嵌套循环（O(n²)）才能解决的问题，优化到线性时间复杂度（O(n)）。
    
    **对撞指针**
        两个指针从序列的两端开始，向中间移动，直到相遇或交错。适合处理已排序数组或需从两端考察
        代码框架：
    def opposite_pointers_template(arr):
        left = 0
        right = len(arr) - 1

        while left < right:
            # 根据 arr[left] 和 arr[right] 的关系执行逻辑
            if condition_is_met(arr[left], arr[right]):
                # 可能需要移动一个指针
                right -= 1
            elif another_condition_is_met(arr[left], arr[right]):
                # 可能需要移动另一个指针
                left += 1
            else:
                # 两个指针同时移动或执行其他操作
                left += 1
                right -= 1
        
        return # 返回结果
    
    **快慢指针
        两个指针从相同的起点出发，以不同速度向前移动。
        代码框架：
    def fast_slow_pointers_template(arr):
        slow = 0
        fast = 0

        while fast < len(arr):
            # 对 fast 指针指向的元素进行处理
            process(arr[fast])

            # 根据特定条件移动 slow 指针
            while some_condition_is_not_met():
                # 窗口收缩，移动 slow 指针
                undo_process(arr[slow])
                slow += 1

            # 更新结果等操作
            update_result()
            
            # 移动 fast 指针，扩大窗口
            fast += 1
3.sliding window

    **核心思想**
        通过维护一个“窗口”（由 left 和 right 两个指针界定的连续区间），并根据特定条件扩大（移动 right 指针）和收缩（移动 left 指针）这个窗口，从而在一次遍历中找到问题的最优解

    **关键**
        窗口每次滑动时，我们不需要重新计算整个窗口内的信息，而是只考虑新移入窗口的元素和移出窗口的元素所带来的变化，从而避免了大量的重复计算
    **代码框架**
    def sliding_window_template(s, ...): # s 可以是字符串或数组
        # 1. 初始化
        left, right = 0, 0           # 窗口的左右边界 [left, right) 或 [left, right]
        window_data = {}             # 用于存储窗口内数据的状态（如字符频率、窗口和等）
        result = ...                 # 用于存储最终结果
        
        # 2. 循环，不断扩大窗口
        while right < len(s):
            # c 是将要移入窗口的元素
            c = s[right]
            right += 1 # 右移窗口，扩大窗口
            
            # 3. 更新窗口内数据
            # ... 在这里进行窗口内数据的更新操作 ...
            # 例如: window_data[c] += 1
            
            # 4. 判断是否需要收缩窗口
            # 当窗口满足某个条件时（condition），开始收缩
            while condition_is_met(window_data):
                # 4.1 在这里更新最终结果
                # result = ... 
                
                # d 是将要移出窗口的元素
                d = s[left]
                left += 1 # 左移窗口，收缩窗口
                
                # 4.2 更新窗口内数据
                # ... 在这里进行窗口内数据的更新操作 ...
                # 例如: window_data[d] -= 1

        return result

