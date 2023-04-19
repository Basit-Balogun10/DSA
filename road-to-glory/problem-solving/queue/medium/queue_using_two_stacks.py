# Enter your code here. Read input from STDIN. Print output to STDOUT
import math
import os
import random
import re
import sys

class StackNode:   
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None
        self.bottom = None
        
    def pop(self):
        if self.top:
            new_top = self.top.next
            old_top = self.top
            
            del self.top
            self.top = new_top
            
            return old_top.data
    
    def push(self, value):
        node = StackNode(value)
        node.next = None

        if not self.top:
            self.top = node
        else:
            self.bottom.next = node

        self.bottom = node


class Queue:
    def __init__(self):
        self.inbox = Stack()
        self.outbox = Stack()
        
    def _fill_outbox(self):
        current = self.inbox.top
            
        while (current):
            popped = self.inbox.pop()
            self.outbox.push(popped)
            
            current = current.next
    
    def enqueue(self, value):
        self.inbox.push(value)
    
    def dequeue(self):
        if not self.outbox.top:
            self._fill_outbox()
        
        self.outbox.pop()
        
    @property
    def front(self):
        if not self.outbox.top:
            self._fill_outbox()
        
        return self.outbox.top

def handle_queue_query(fptr, queue, query):
    query_type = int(query[0])
    
    if query_type == 1:
        enqueue_val = int(query[1])
        queue.enqueue(enqueue_val)
    elif query_type == 2:
        queue.dequeue()
    elif query_type == 3:
        fptr.write(str(queue.front.data) + '\n')
        

with open(os.environ['OUTPUT_PATH'], 'w') as fptr:
    queue = Queue()
    no_of_queries = int(input().rstrip())
    
    for _ in range(no_of_queries):
        query = input().rstrip().split()
        handle_queue_query(fptr, queue, query)
        
# https://www.hackerrank.com/challenges/queue-using-two-stacks/problem?isFullScreen=true