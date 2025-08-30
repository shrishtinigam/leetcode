# Last updated: 8/30/2025, 8:19:58 PM
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:

    
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        nodes = {}

        def clone(node):
            if(node in nodes):
                return nodes[node]
            
            node_copy = Node(node.val)
            nodes[node] = node_copy

            for neighbor in node.neighbors:
                node_copy.neighbors.append(clone(neighbor))
            
            return node_copy


        
        return clone(node)