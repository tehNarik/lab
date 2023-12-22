class Record:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def get_str(self):
        return str(self.key) + ' - ' + self.value + '\n'

    def get_value(self):
        return self.value

    def get_key(self):
        return self.key

    def update(self, value):
        self.value = value