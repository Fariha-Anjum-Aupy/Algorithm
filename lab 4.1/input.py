import random  
  
def generateCase():  
  
    ns = [1000,5000,10000,50000,100000]  
    t = len(ns)   
    with open("input1.txt", "w") as file:  
  
        file.write(f"{t}\n")  
        for i in range(t):  
            n = ns[i]  
            file.write(f"{n}\n")  
            array = [random.randint(1, int(1e5)) for _ in range(n)]  
            file.write(" ".join(map(str, array)) + "\n")  
            x = random.choice(array)  
            y = random.randint(1,int(1e5))  
            z = random.randint(1,100)  
            file.write(f"{x if z<=70 else y}\n")  
  
generateCase()  
  
print("Test cases generated and saved to 'test_cases.txt'")