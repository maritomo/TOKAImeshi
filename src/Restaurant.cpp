//
// Created by Tomoo MARI on 2018/09/02.
//

#include <iostream>
#include <iomanip>

#include "Restaurant.h"

#include "TRandom.h"

Restaurant::Restaurant(std::string name, double price,
                       double required_time, double weight) :
        m_name(name), m_price(price), m_requiredTime(required_time),
        m_weight(weight) {
  required_time /= 60; // min -> hour
}

Restaurant::~Restaurant() {}

void Restaurant::AddClosedWday(wDay day){
  m_closedWday.push_back(static_cast<int>(day));
}

void Restaurant::AddOpenTime(struct openTime* time) {
  m_openTime.push_back(time);
}

int Restaurant::Check() {

  time_t now = time(NULL);
  struct tm* pnow = localtime(&now);

  int now_wday = pnow->tm_wday;

  if(m_closedWday.size()>0) {
    for(auto itr = m_closedWday.begin(); itr!=m_closedWday.end(); ++itr) {
      if(now_wday == *itr) {
        m_remainingTime = 0;
        m_isOpen = 0;
        return m_isOpen;
      }
    }
  }

  double now_h = pnow->tm_hour;
  now_h += (double)pnow->tm_min / 60;

  for(auto itr = m_openTime.begin(); itr!=m_openTime.end(); ++itr) {
    if(now_h >= (*itr)->time_open && now_h < (*itr)->time_close) {
      m_remainingTime = (*itr)->time_close - now_h;
      m_isOpen = 1;
      return m_isOpen;
    }
  }

  m_remainingTime = 0;
  m_isOpen = 0;
  return m_isOpen;
}

////////////////////////////////////////////////

List::List() {}
List::~List() {}

void List::Add(Restaurant* p) {
  m_list.push_back(p);
}

std::string List::Random(){
  double amp = 0;
  std::vector<double> wList;

  for(auto itr = m_list.begin(); itr!=m_list.end(); ++itr) {
    double w = 0;
    if((*itr)->Check()==1) {
      w = (*itr)->GetWeight();
    }
    wList.push_back(w);
    amp += w;
  }

  auto itr = wList.begin();
  auto itr2 = m_list.begin();

  gRandom->SetSeed(time(NULL));
  double rand = amp * gRandom->Rndm();

  double sum = 0;
  for(; itr!=wList.end(); ++itr, ++itr2) {
    sum += (*itr);
    if(rand < sum) {
      std::cout << "XXXXXXXXXXXXXXXXXXXXXXX\n";
      std::cout << (*itr2)->GetName() << "\n";
      std::cout << "XXXXXXXXXXXXXXXXXXXXXXX\n";
      return (*itr2)->GetName();
    }
  }

  std::cout << "No matching restaurant !\n";
  return "";
}

void List::Show() {
  std::cout << "------------------------------------\n";
  std::cout << "Name\tuntil close[h]\n";
  std::cout << "------------------------------------\n";

  for(auto itr = m_list.begin(); itr!=m_list.end(); ++itr) {
    if((*itr)->Check()==1) {
      std::cout << (*itr)->GetName() << "\t" << std::fixed << std::setprecision(1)
                << (*itr)->GetRemainingTime() << "\n";
    }
  }
  std::cout << "------------------------------------\n";
}