
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        """ Store the data, and set next to None"""

    def __str__(self):
        self.head = None
        """ Return a string representation of the data """


class Storage:
    def __init__(self):
        self.head = None
        """ Creates an empty Storage class. Sets head to None. """

    def push(self, data):

        node = Node(data)
        if self.head is None:
            self.head = node
            return

        Node.next = self.head
        self.head = Node
        """ Create a Node to hold the data, then put it at the head of the list. """

    def pop(self):

        node = Node()
        self.head = node

        if node is None:
            return False
        
        print(node.data)
        self.head = node.next
        return True
        """ Remove the head Node and return its data. """

    def peek(self):

        node = Node()
        if node is None:
            print("Null")
            return False
        print(node.data)
        return True
    
        """ Return the data from the head Node, without removing it. """

    def isempty(self):
        node = Node()
        if node is None:
            return True
        else:
            return False
        
        """ Return True if the list is empty, otherwise False """