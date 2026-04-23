from collections import OrderedDict

class LRUCache(object):

    def __init__(self, capacity):
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key):
        if key not in self.cache:
            return -1
        
        value = self.cache[key]
        del self.cache[key]          # remove
        self.cache[key] = value      # reinsert (moves to end)

        return value

    def put(self, key, value):
        if key in self.cache:
            del self.cache[key]      # remove old
        
        self.cache[key] = value      # insert at end

        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)  # remove LRU