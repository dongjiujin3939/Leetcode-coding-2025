# Leetcode-coding-2025
Leetcode coding  
1.hash
#include <unordered_map>
#键值对的hash映射，键唯一 
  #需要声明key和value的数据类型
#插入和更新
  #[]便捷操作符，插入和创建，没有则创建，有则更新
  #.insert(), 插入操作，接受std::pair,如果有此键，无任何操作
#访问元素
  #[]便捷操作符，访问元素，直接通过key访问对应的value，若不存在则自动插入一个具有默认构造值的元素
  #.at(),若没有该键，则报错
#删除元素
  #.erase()通过键，删除对应的键值对
#常用操作
  #.find(),  查找键，返回指向元素的迭代器
  #.count(), 查找键，返回0或1
  #.size(), 返回容器元素
  #.empty(), 容器是否为空
  #.clear(), 清空容器
#include <unordered_set>
#唯一元素的hash集合
  #适用于检查元素是否在集合中
#声明
  #需指明数据类型
#基本操作
  #.insert(), 插入，元素已存在，不会操作
  #.find(), 查找键，返回指向元素的迭代器
  #.count(), 查找键，返回0或1
  #.erase(), 删除
  #.size(), 返回容器大小
  #.empty(),容器是否为空
  #.clear(), 清空容器
  hash 适用于快速查找，插入和删除，且不关心元素顺序
