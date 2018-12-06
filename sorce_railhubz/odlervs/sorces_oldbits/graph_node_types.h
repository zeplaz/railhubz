
// the graphserch functions were sorced From Author: Mat Buckland.
//modifcations made to meet needs

#ifndef GRAPH_NODE_TYPES_H
#define GRAPH_NODE_TYPES_H

#include <list>
#include <SFML/Graphics.hpp>

class GraphNode
{
protected:

   int        m_iIndex;

public:

  GraphNode():m_iIndex(-1){}
  GraphNode(int idx):m_iIndex(idx){}

  virtual ~GraphNode(){}

  int  Index()const{return m_iIndex;}
  void SetIndex(int NewIndex){m_iIndex = NewIndex;}

 };


template <class extra_info = void*>
class NavGraphNode : public GraphNode
{
protected:

  sf::Vector2f     m_vPosition;
  extra_info  m_ExtraInfo;

public:


  NavGraphNode():m_ExtraInfo(extra_info()){}

  NavGraphNode(int      idx,
               sf::Vector2f pos):GraphNode(idx),
                             m_vPosition(pos),
                             m_ExtraInfo(extra_info())
{}


  virtual ~NavGraphNode(){}

  sf::Vector2f   Pos()const{return m_vPosition;}
  void       SetPos(sf::Vector2f NewPosition){m_vPosition = NewPosition;}

  extra_info ExtraInfo()const{return m_ExtraInfo;}

  void SetExtraInfo(extra_info info){m_ExtraInfo = info;}
  };

#endif
