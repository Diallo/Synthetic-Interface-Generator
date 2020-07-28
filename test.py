import random
from copy import deepcopy

def print_society(society: list) -> None:
    '''
    Pretty prints a given society.

    Parameters:
        society (list): The society to be printed.
    '''
    
    print('\n'.join([' '.join(row) for row in society]))

def build_society(m: int, n: int) -> list:
    '''
    Builds an m by n society randomly assigned with * and -

    Parameters:
        m (int): The number of rows of the society.
        n (int): The number of columns of the society.

    Returns:
        the resulting randomly built society.
    '''
    indiv = ['-','*']
    society = [[random.choice(indiv) for j in range(n)] for i in range(m)]
    return society



def destiny(society: list, coordinates: tuple) -> str:
    '''
    Determines the liveliness of the cell in coordinates in the next generation.

    Parameters:
        society      (list): The society.
        coordinates (tuple): The tuple representing the coordinates whose
                             destiny is to be determined.

    Returns:
        the cell's destiny.
    '''
    def checkNeighbours(i,j):
        h = len(society)
        w = len(society[0])
        dead, live = 0,0
        neighbours = [[i-1,j-1],[i-1,j],[i-1,j+1],[i,j-1],[i,j+1],[i+1,j-1],[i+1,j],[i+1,j+1]]
        for coord in neighbours:
            if 0 <= coord[0] < h:
                if 0 <= coord[1] < w:
                    if society[coord[0]][coord[1]] == '*':
                        live += 1
                    else:
                        dead +=1
        if society[i][j] == '*':
            if live < 2 or live > 3:
                return '-'
        else:
            if live == 3:
                return '*'
        return society[i][j]
    
    a = int(coordinates[0])
    b = int(coordinates[1])
    return checkNeighbours(a,b)
                       

#### TODO: Remove below


def evolve(society: list, n: int) -> tuple:

  

    new_society = deepcopy(society)
   
    for i in range(n):
        temp_society = deepcopy(new_society)
        for row in range(len(society)):
            for col in range(len(society[0])):
                temp_society[row][col] = destiny(new_society,(row,col))
        
        # If you just evolved it and nothing changed 
        if temp_society == new_society:
            return (new_society,i)
        new_society = temp_society
    
    return (new_society,n)
        
    
    
    
        
def migrate(society: list) -> list:
    '''
    Causes a society to migrate based on the population census.

    Parameters:
        society (list): The given society.

    Returns:
        the resulting society after migration.
    '''
    new_society = [[cell for cell in row] for row in society]
    ranked_society = sorted(new_society, reverse=True, key=lambda row: row.count('*'))
    return ranked_society

def main():
    # Define some constants.
    m, n = 6, 5
    num_of_evolutions = 10

    # ======= DO NOT EDIT THE CODE SNIPPETS BEYOND THIS POINT ========
    # (1) Build a random society of m by n.
    society = build_society(m, n)
    print("Initial Society:")
    print_society(society)

    # (2) Evolve the society for num_of_evolution iterations.
    result, num_evolutions_to_stability = evolve(society, num_of_evolutions)
    print("After {} evolutions, resulting society:"
        .format(num_of_evolutions))
    print_society(result)
    print('Number of evolutions to achieve stability:',
        num_evolutions_to_stability)

    # (3) Perform migration on the society.
    after_migration = migrate(result)
    print("Resulting society after migration:")
    print_society(after_migration)

if __name__ == '__main__':
    main()
    
  
    
