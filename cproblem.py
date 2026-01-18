import sys

def solve():
    # ইনপুট থেকে n এবং স্ট্রিং s পড়া
    try:
        line1 = sys.stdin.readline().strip()
        if not line1: return
        n = int(line1)
        s = sys.stdin.readline().strip()
    except EOFError:
        return

    # ১. চেক করা স্ট্রিংটি ইতিমধ্যে সর্ট করা কি না
    is_sorted = True
    for i in range(n - 1):
        if s[i] > s[i+1]: # যদি কোথাও ১ এর পর ০ থাকে
            is_sorted = False
            break
    
    if is_sorted:
        print("Bob")
        return

    # ২. Alice-এর জন্য একটি জয়ী মুভ খুঁজে বের করা
    # প্রথম '1' এবং শেষ '0' এর ইনডেক্স বের করা
    first_one = s.find('1')
    last_zero = s.rfind('0')
    
    # ইনডেক্সগুলো ১-ভিত্তিক (1-based) হতে হবে
    # এবং অবশ্যই আরোহী ক্রমে (increasing order) প্রিন্ট করতে হবে
    print("Alice")
    print(2)
    print(f"{first_one + 1} {last_zero + 1}")

def main():
    # টেস্ট কেসের সংখ্যা পড়া
    line = sys.stdin.readline().strip()
    if line:
        t = int(line)
        for _ in range(t):
            solve()

if __name__ == "__main__":
    main()