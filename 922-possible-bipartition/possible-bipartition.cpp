class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        enum COLOR_CONSTANT{
            GREEN = -1,        
            NOT_COLORDED,       
            BLUE                
        };
        
        
        if( n == 1 || dislikes.size() == 0 ){
    
            return true;
        }

        unordered_map< int, vector<int> > dislikeTable;
        
        unordered_map< int, int> colorTable;
        
  
        
        std::function< bool( int, int ) > helper;
        helper = [&]( int personID, int color)->bool{
            
    
            colorTable[personID] = color;
            
            for( const int& theOther : dislikeTable[ personID ] ){
                
                if( colorTable[theOther] == color ){
                
                    return false;
                }
                
                if( colorTable[theOther] == NOT_COLORDED && ( !helper(theOther, -color) ) ){
                    
                    return false;
                }
            }
            
            return true;
            
        };
        
    
        for( const auto& relation : dislikes ){
            
            int p1 = relation[0], p2 = relation[1];
            
            dislikeTable[p1].emplace_back( p2 );
            dislikeTable[p2].emplace_back( p1 );
            
        }
        
        for( int personID = 1 ; personID <= n ; personID++){
            
            if( colorTable[personID] == NOT_COLORDED && ( !helper(personID, BLUE) ) ){
                    
                    return false;
            }
        }
        

        return true;        
    }
};