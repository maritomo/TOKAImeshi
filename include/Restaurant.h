//
// Created by Tomoo MARI on 2018/09/02.
//
#ifndef APP_RESTAURANT_H
#define APP_RESTAURANT_H

#include <vector>
#include <string>

enum wDay {
  Sun, Mon, Tue, Wed, Thu, Fri, Sat,
};

struct openTime {
  double time_open; // [h]
  double time_close;
};

class Restaurant {
public:
  Restaurant(std::string name, double price,
             double required_time = 60, double weight = 1);
  ~Restaurant();
  void AddClosedWday(wDay);
  void AddOpenTime(struct openTime*);
  int Check();

  void SetWeight(double weight) { m_weight = weight; };
  std::string GetName() { return m_name; };
  double GetWeight() { return m_weight; };
  double GetRemainingTime() { return m_remainingTime; };

private:
  std::string m_name;
  std::vector<int> m_closedWday;
  std::vector<struct openTime*> m_openTime;

  double m_price;
  double m_requiredTime; // [h]
  double m_weight;

  int m_isOpen;
  double m_remainingTime;
};

class List {
public:
  List();
  ~List();
  void Add(Restaurant*);
  std::string Random();
  void Show();

private:
  std::vector<Restaurant*> m_list;
};

#endif //APP_RESTAURANT_H
