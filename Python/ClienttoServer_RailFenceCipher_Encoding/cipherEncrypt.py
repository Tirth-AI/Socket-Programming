def railFenceCipherEncrypt(text, key):
    textLength = len(text)
    
    rail = [[ "\n" for i in range(textLength)]
             for j in range(key)]
    
    direction = False
    row, col = 0,0
    
    for i in range(textLength):
        if row == 0 or row  == key -1:
            direction = not direction
        
        rail[row][col] = text[i]
        col+=1
        
        if direction:
            row+=1
        else:
            row-=1
            
    
    result = ""
    for i  in range(key):
        for j in range(textLength):
            if rail[i][j] != "\n":
                result += rail[i][j]
    
    return result
    
