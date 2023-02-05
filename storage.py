
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        """ Store the data, and set next to None"""

    def __str__(self):
        if self.data is not None:
            return (str(self.data))
        """ Return a string representation of the data """


class Storage:
    def __init__(self):
        self.head = None
        self.next = None
        """ Creates an empty Storage class. Sets head to None. """

    def push(self, data):

        node = Node(data)
        if self.head is None:
            self.head = node
            return

        node.next = self.head
        self.head = node
        """ Create a Node to hold the data, then put it at the head of the list. """

    def pop(self):

        if self.head is None:
            print("Empty.")
            return
        
        node = self.head
        self.head = node.next
        return node.data
        """ Remove the head Node and return its data. """

    def peek(self):

        node = self.head
        if node is None:
            print("Null")
            return False
    
        return node.data
    
        """ Return the data from the head Node, without removing it. """

    def isempty(self):
        node = self.head
        if node is None:
            return True
        else:
            return False
        
        """ Return True if the list is empty, otherwise False """