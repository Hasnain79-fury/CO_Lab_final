#include<bits/stdc++.h>
using namespace std ;

int numVertices, numEdges, tt=0;
vector< string > vertices;
set< pair< int, pair< string, string > > > edges ;
set< pair< int, pair< string, string > > > A ;
vector< set< string > > sets ;

void getInput()
{
    freopen( "labFinal.txt", "r", stdin ) ;
    cin >> numVertices >> numEdges ;
    for( int i=0; i<numVertices; i++ )
    {
        string temp ;
        cin >> temp ;
        vertices.push_back(temp) ;
    }

    string u, v ;
    int weight ;
    pair< int, pair< string, string > > edge ;
    for(int i=0; i<numEdges; i++)
    {
        cin >> u >> v;
        cin >> weight ;
        tt += weight ;
        edge.first = weight ;
        edge.second.first = u ; 
        edge.second.second = v ;
        edges.insert( edge ) ;
    }
}

int findSet( string u )
{
    int count=0;
    for(auto i: sets)
    {
        auto a= i.find(u);
        if(a != i.end())
        {
            break;
        }
        count++;
    }
    return count;
}

void Union( string u, string v )
{
    set< string > temp ;
    int index_u = findSet( u ) ;
    int index_v = findSet( v ) ;
   
    for( auto a: sets[index_v] )
    {
        sets[index_u].insert(a) ;
    }

    sets.erase( sets.begin() + index_v ) ;
}

void MST()
{
    for( int i=0; i < numVertices; i++ )
    {
        set<string> temp ;
        temp.insert( vertices[i] ) ;
        sets.push_back( temp ) ;
    }

    for( auto i : edges )
    {
        string u, v ;
        u = i.second.first ;
        v = i.second.second ;
        if( findSet(u) != findSet(v) )
        {
            A.insert( i ) ;
            Union( u, v ) ;
        }
    }
}


int main()
{
    int total = 0 ;
    getInput() ;
    MST() ;

    for ( auto ed : edges )
    {
        cout << ed.second.first << " -> " << ed.second.second << " : " << ed.first << endl ;
    }

    cout << "\nThe new tree edges :\n\n" ;
    for ( auto ed : A )
    {
        total += ed.first ;
        cout << ed.second.first << " -> " << ed.second.second << " : " << ed.first << endl ;
    }

    cout << endl << "Total weight : " << total << endl ;
    cout << "Road can be eliminated : " << tt-total << endl ;
    cout << "Maximum " << (tt-total)*1 << "$ can be saved.\n\n" ;

}