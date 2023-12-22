import tkinter as tk
from tkinter import filedialog, messagebox
from File2 import File2
import random
import string
from Record import Record

file_object = File2()


def find():
    key = entry1.get()
    file_object.find_el(int(key))


def add():
    key = entry1.get()
    new_value = entry2.get()
    file_object.add(key, new_value)

    large_window.delete(1.0, tk.END)
    large_window.insert(tk.END, file_object.print_info())


def delete():
    key = entry1.get()
    file_object.delete(key)

    large_window.delete(1.0, tk.END)
    large_window.insert(tk.END, file_object.print_info())
    entry1.delete(0, tk.END)
    entry2.delete(0, tk.END)

def update():
    key = entry1.get()
    new_value = entry2.get()

    file_object.update(key, new_value)
    large_window.delete(1.0, tk.END)
    large_window.insert(tk.END, file_object.print_info())
    entry1.delete(0, tk.END)
    entry2.delete(0, tk.END)

def save():
    text_content = large_window.get("1.0", tk.END)
    with open("data.txt", "w") as file:
        file.write(text_content)

def load():
    file_object.all_delete()
    with open('data.txt', 'r') as file:
        content = file.read()
        lines = content.splitlines()
        counter = 0
        is_main = True
        for line in lines:
            if line.startswith("=== Primary Area ===")  or line.startswith(
                    "Page"):
                continue
            if line.startswith("=== Overflow Area ==="):
                is_main = False
                continue
            if line.startswith("=== Indexes ==="):
                break
            line = line.strip()
            line = line.split()
            if len(line)==0:
                continue
            rec = Record(int(line[0]), line[2])
            file_object.load_record(rec, is_main)
            counter += 1
        print(file_object.print_info())
        large_window.delete(1.0, tk.END)
        large_window.insert(tk.END, file_object.print_info())
        print(counter)


def generate_random_string(max_length):
    all_letters = string.ascii_letters
    length = random.randint(1, max_length)
    random_string = ''.join(random.choice(all_letters) for _ in range(length))
    return random_string

def generate():
    file_object.all_delete()
    for i in range(100):
        temp_val = generate_random_string(10)
        record = Record(i+1, temp_val)
        file_object.add_record(record)

    large_window.delete(1.0, tk.END)
    large_window.insert(tk.END, file_object.print_info())


main_window = tk.Tk()
main_window.title("My GUI")

label1 = tk.Label(main_window, text="Key:", font=("Arial", 12, "bold"))
label2 = tk.Label(main_window, text="Value:", font=("Arial", 12, "bold"))

entry1 = tk.Entry(main_window)
entry2 = tk.Entry(main_window)

add_button = tk.Button(main_window, text="Add", width=15, command=add)
search_button = tk.Button(main_window, text="Search", width=15, command=find)
delete_button = tk.Button(main_window, text="Delete", width=15, command=delete)
update_button = tk.Button(main_window, text="Update", width=15, command=update)
save_button = tk.Button(main_window, text="Save", width=15, command=save)
load_button = tk.Button(main_window, text="Load", width=15, command=load)
generate_button = tk.Button(main_window, text="Generate", width=15, command=generate)


def on_scroll(*args):
    large_window.yview(*args)
large_window = tk.Text(main_window, height=20, width=75)


label1.grid(row=0, column=0, sticky="w", padx=10, pady=10)
entry1.grid(row=0, column=1, padx=10, pady=10)
label2.grid(row=0, column=2, sticky="w", padx=10, pady=10)
entry2.grid(row=0, column=3, padx=10, pady=10)
add_button.grid(row=1, column=0, pady=10)
search_button.grid(row=1, column=1, pady=10)
delete_button.grid(row=1, column=2, pady=10)
update_button.grid(row=1, column=3, pady=10)
save_button.grid(row=2, column=0, pady=10)
load_button.grid(row=2, column=1, pady=10)
generate_button.grid(row=2, column=2, pady=10)
large_window.grid(row=3, column=0, columnspan=4, padx=10, pady=10)

main_window.mainloop()
