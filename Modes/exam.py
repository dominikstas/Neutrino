import sys

def main():
    #in case of any argument error:
    if len(sys.argv) < 2:
        print("Usage: python exam.py [setName]")
    else:
        setName = sys.argv[1]
        #this just show me that everything is fine
        print(f"Set Name: {setName}")

if __name__ == "__main__":
    main()