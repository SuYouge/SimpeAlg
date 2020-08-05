"""
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
"""
python链表实现 https://www.jb51.net/article/133798.htm
"""
class ListNode: # 节点类
    def __init__(self,data):
        self.data = data
        self.next = None
        return
    def has_value(self,value):
        if self.data == value:
            return True
        else:
            return False

class SingleLinkedList():
    def __init__(self):
        self.head = None
        self.tail = None
        return
    def add_list_item(self,item):
        """
        通过add_list_item()添加列表元素。先检测是不是ListNode的实例
        如果不是，就新建一个节点。如果列表还是空的话，就把该节点当作头节点
        如果不是空，就将当前节点指向下一个元素（也就是刚新添加的节点）。把新节点添加到列表当中
        """
        if not isinstance(item,ListNode):
            item = ListNode(item)
        if self.head is None:
            self.head = item
        else:
            self.tail.next = item
        self.tail = item
        return
    def list_length(self):
        """
        list_length()方法计算节点数量，返回列表的长度。在一个循环当中循环列表，self.next依次指向下一个节点
        :return:
        """
        count = 0
        current_node = self.head
        while current_node is not None:
            count = count + 1
            current_node = current_node.next
        return count
    def output_list(self):
        """
        output_list()用来输出新的节点值
        :return:
        """
        current_node = self.head
        while current_node is not None:
            print(current_node)
            current_node = current_node.next
        return
    def unordered_search(self,value):
        """
        查询整个列表使用unordered_search()。它需要使用一个额外的参数帮助查询。列表的头是切入点。
        :param value:
        :return:
        """
        current_node = self.head
        node_id = 1
        result = []
        while current_node is not None:
            if current_node.has_value(value):
                result.append(node_id)
            current_node = current_node.next
            node_id = node_id + 1
        return result
    def remove_list_item_by_id(self,item_id):
        """
        从列表中移除一个元素
        从列表中移除一个节点 时，指向该节点索引需要被移动到
        被移除节点的下一个节点。被移除的节点会由python的垃圾回收机制清除
        :param item_id:
        :return:
        """
        current_id = 1
        current_node = self.head
        previous_node = None
        while current_node is not None:
            if current_node == item_id:
                if previous_node is not None:
                    previous_node.next = current_node.next
                else:
                    self.head = current_node.next
                    return
            previous_node = current_node
            current_node = current_node.next
            current_id = current_id + 1


class DoubleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        return
    def list_length(self):
        """
        list_length()方法计算节点数量，返回列表的长度。在一个循环当中循环列表，self.next依次指向下一个节点
        :return:
        """
        count = 0
        current_node = self.head
        while current_node is not None:
            count = count + 1
            current_node = current_node.next
        return count
    def output_list(self):
        """
        output_list()用来输出新的节点值
        :return:
        """
        current_node = self.head
        while current_node is not None:
            print(current_node)
            current_node = current_node.next
        return
    def unordered_search(self,value):
        """
        查询整个列表使用unordered_search()。它需要使用一个额外的参数帮助查询。列表的头是切入点。
        :param value:
        :return:
        """
        current_node = self.head
        node_id = 1
        result = []
        while current_node is not None:
            if current_node.has_value(value):
                result.append(node_id)
            current_node = current_node.next
            node_id = node_id + 1
        return result
    def add_list_item(self,item):
        if isinstance(item,ListNode):
            if self.head is None:
                self.head = item
                item.previous = None
                item.next = None
                self.tail = item
            else:
                self.tail.next = item
                item.previous = self.tail
                self.tail = item
            return

    def remove_list_item_by_id(self,item_id):
        current_id = 1
        current_node = self.head
        while current_node is not None:
            previous_node = current_node.previous
            next_node = current_node.next
            if current_id == item_id:
                if previous_node is not None:
                    previous_node.next = next_node
                    next_node.previous = previous_node
                else:
                    self.head = next_node
                    if next_node is not None:
                        next_node.previous = None
                return
            current_node = next_node
            current_id = current_id + 1
        return

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
if __name__ == '__main__':
    node1 = ListNode(15)
    node2 = ListNode(8.2)
    item3 = "berlin"
    node4 = ListNode(15)
    track = SingleLinkedList()
    print("Track length: %i"% track.list_length())
    for current_item in [node1,node2,item3,node4]:
        track.add_list_item(current_item)
        print("Track length: %i"% track.list_length())
        track.output_list()
    pass