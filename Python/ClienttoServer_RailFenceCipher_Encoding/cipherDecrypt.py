def railFenceCipherDecrypt(text, key):
    rail = [["\n" for i in range(len(text))]
            for j in range(key)]
    
    direction = None
    row, col = 0,0
    for i in range(len(text)):
        if row == 0:
            direction = True
        elif row == key-1:
            direction = False
        
        rail[row][col] = "*"
        col += 1
        
        if direction:
            row += 1
        else:
            row -= 1
        
    index = 0
    
    for i in range(key):
        for j in range(len(text)):
            if rail[i][j] == "*" and index < len(text):
                rail[i][j] = text[index]
                index += 1
    
    result = ""     
    direction = None
    row, col = 0,0
    for i in range(len(text)):
        if row == 0:
            direction = True
        elif row == key-1:
            direction = False
        
        if rail[row][col] != "*":
            result += rail[row][col]
            col += 1
        
        if direction:
            row += 1
        else:
            row -= 1
    
    return result