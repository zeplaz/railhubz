//railhubz.cpp
#include "railhubz.hpp"

railhubz::railhubz(sf::Vector2f hub_l)
{
  hub_id = next_hub_id;
  next_hub_id++;

  hub_location = hub_l;
  cr_hubgraphic.setRadius(20.f);
  cr_hubgraphic.setPosition(hub_location);
  cr_hubgraphic.setFillColor(sf::Color::Green);
 }

void railhubz::draw(sf::RenderWindow &window)
 {
  window.draw(cr_hubgraphic);
 }

void railhubz::add_R_line(R_linez* r_lin_prt)
 {
  line_connections.push_back(r_lin_prt);
 }

sf::Vector2f railhubz::get_location() const
 {
  return(hub_location);
 }

void railhubz::add_train_toque(trainz* tr_prt)
 {
  train_que.push(tr_prt);
 }

auto railhubz::line_connect_ref() -> std::vector<R_linez*>(&)
{return line_connections;}

void railhubz::exit_train()
 {
  train_que.pop();
 }

trainz* railhubz::rtn_priority_train()
 {
  return train_que.top();
 }
