from Record import Record
from tkinter import messagebox

class File2:
    def __init__(self):
        self.count_page = 10 # кількість записів на сторінці
        self.ALPHA = 0.4
        self.i_records = {}
        self.overflow_records = []
        self.index_records = []
        self.count_i_records = 0
        self.count_overflow_records = 0
        self.find_counter = 0

    def all_delete(self):
        self.i_records = {}
        self.overflow_records = []
        self.count_i_records = 0
        self.count_overflow_records = 0

    def add_record(self, rec):
        if self.count_i_records*self.ALPHA>self.count_overflow_records*(1-self.ALPHA):
            self.overflow_records.append(rec)
            self.count_overflow_records += 1
        else:
            if not self.i_records:
                self.i_records[1] = []
            last_key = max(self.i_records)
            if len(self.i_records[last_key])==self.count_page:
                self.i_records[rec.get_key()] = []
            last_key = max(self.i_records)
            self.i_records[last_key].append(rec)
            self.count_i_records += 1

    def load_record(self, rec, is_main):
        if is_main:
            if not self.i_records:
                self.i_records[1] = []
            last_key = max(self.i_records)
            if len(self.i_records[last_key])==self.count_page:
                self.i_records[rec.get_key()] = []
            last_key = max(self.i_records)
            self.i_records[last_key].append(rec)
            self.count_i_records += 1
        else:
            self.overflow_records.append(rec)
            self.count_overflow_records += 1



    def print_info(self):
        result_str = "=== Primary Area ===\n"
        counter = self.count_page
        c=1
        index_text = "\n=== Indexes ===\n"
        for page_number, record in self.i_records.items():
            index_text += record[0].get_str()
            result_str += f"Page {c}:\n"
            c += 1
            for i in record:
                result_str += "   " + i.get_str()
                counter += 1

        result_str += "=== Overflow Area ===\n"
        for record in self.overflow_records:
            result_str += record.get_str()
        result_str += index_text

        return result_str

    def delete(self, key_):
        for i in self.overflow_records:
            if str(i.get_key())==key_:
                self.overflow_records.remove(i)
                self.count_overflow_records -= 1
                return
        for key, value in self.i_records.items():
            for i in value:
                if int(i.get_key())==int(key_):
                    self.i_records[key].remove(i)
                    self.count_i_records -= 1
                    return
        messagebox.showinfo("Error", "Key doesn't exists.")

    def add(self, key_, value):
        new_record = Record(int(key_), value)

        # Перевірка, чи запис із таким ключем вже існує
        for i in self.overflow_records:
            if int(i.get_key()) == int(key_):
                messagebox.showinfo("Error", "Key already exists.")
                return
        for key, records in self.i_records.items():
            for i in records:
                if i.get_key() == int(key_):
                    messagebox.showinfo("Error", "Key already exists.")
                    return
        print(self.count_i_records, self.count_overflow_records)
        if self.count_i_records * self.ALPHA > self.count_overflow_records * (1 - self.ALPHA):
            # Додати в область переповнення
            self.overflow_records.append(new_record)
            self.overflow_records.sort(key=lambda x: x.get_key())
            self.count_overflow_records += 1
        else:


            # Додати в основну область
            if not self.i_records:
                self.i_records[int(key_)] = []
            keys_list = list(self.i_records.keys())
            last_key = keys_list[0]
            for k in keys_list:
                if k<=int(key_):
                    last_key = k
                else:
                    break


            temp_arr = []
            flag = True
            for i in self.i_records[last_key]:
                if i.get_key()>int(key_) and flag:
                    temp_arr.append(Record(int(key_), value))
                    self.count_i_records += 1
                    flag = False
                temp_arr.append(i)
            if flag:
                temp_arr.append(Record(int(key_), value))
                self.count_i_records += 1
            self.i_records[last_key] = temp_arr[:self.count_page]
            for i in temp_arr[self.count_page:]:
                self.sort_over_records(i)
            print("===\n", self.print_info())


    def sort_over_records(self, rec):
        temp_arr = []
        flag = True
        for i in self.overflow_records:
            if i.get_key()>rec.get_key() and flag:
                temp_arr.append(rec)
                self.count_overflow_records += 1
                flag = False
            temp_arr.append(i)
        self.overflow_records = temp_arr

    def update(self, key_, value):
        for i in self.overflow_records:
            if int(i.get_key())>int(key_):
                break
            if int(i.get_key())==int(key_):
                i.update(value)
                return

        keys_list = list(self.i_records.keys())
        last_key = keys_list[0]
        for k in keys_list:
            if k <= int(key_):
                last_key = k
            else:
                break
        for i in self.i_records[last_key]:
            if i.get_key()==int(key_):
                i.update(value)
                return
        messagebox.showinfo("Error", "Key already exists.")

    def binary_search(self, key_, records):
        low = 0
        high = len(records) - 1
        counter = 0
        while low <= high:
            mid = (low + high) // 2
            current_record = records[mid]
            self.find_counter += 1
            if current_record.get_key() == int(key_):
                messagebox.showinfo("Success", current_record.get_str()+"\nCount of comparisons: "+str(self.find_counter))
                self.find_counter = 0
                return True
            elif current_record.get_key() < int(key_):
                low = mid + 1
            else:
                high = mid - 1


    def find_el(self, key_):
        self.find_counter = 0
        keys_list = list(self.i_records.keys())
        last_key = keys_list[0]
        left, right = 0, len(keys_list)-1
        while left <= right:
            mid = (left + right) // 2
            self.find_counter += 1
            if keys_list[mid]>int(key_):
                right = mid
            elif keys_list[mid]<=int(key_) and keys_list[mid+1]<=int(key_):
                left = mid
            else:
                if self.binary_search(key_, self.i_records[keys_list[mid]]):
                    return
                else:
                    break
        self.find_counter = 0
        # Пошук у файлі з нещільним індексом
        '''for key, records in self.i_records.items():
            if len(records) > 0 and records[0].get_key() <= int(key_) <= records[-1].get_key():
                if self.binary_search(key_, records):
                    return'''

        # Пошук у області переповнення
        if len(self.overflow_records) > 0 and self.overflow_records[0].get_key() <= int(key_) <= self.overflow_records[
            -1].get_key():
            if self.binary_search(key_, self.overflow_records):
                return

        messagebox.showinfo("Error", "Key doesn't exists.")

