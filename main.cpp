#include <iostream>
#include "Restaurant.h"
#include <unistd.h>

int main() {

  /* Restaurant (
   *    name,
   *    price,
   *    (required_time [min]),
   *    (weight)
   * )
   */

  List list;

  Restaurant uoyasu("uoyasu", 1000, 45);
  uoyasu.AddClosedWday(Tue);
  struct openTime t_uoyasu[2] = { {11.5,14}, {17,21} };
  for(int i=0; i<2; ++i)
    uoyasu.AddOpenTime(t_uoyasu+i);
  list.Add(&uoyasu);

  Restaurant pallet("pallet", 1000, 60);
  pallet.AddClosedWday(Tue);
  struct openTime t_pallet = {11.5, 15};
  pallet.AddOpenTime(&t_pallet);
  list.Add(&pallet);

  Restaurant parent("parent", 1000, 60);
  parent.AddClosedWday(Mon);
  struct openTime t_parent = {11, 22};
  parent.AddOpenTime(&t_parent);
  list.Add(&parent);

  Restaurant seven("seven", 500, 20);
  struct openTime t_seven = {0, 24};
  seven.AddOpenTime(&t_seven);
  list.Add(&seven);

  Restaurant tsuruya("tsuruya", 700, 40);
  tsuruya.AddClosedWday(Mon);
  struct openTime t_tsuruya[2] = { {11,15}, {17,19} };
  for(int i=0; i<2; ++i)
    tsuruya.AddOpenTime(t_tsuruya+i);
  list.Add(&tsuruya);

  Restaurant sukiya("sukiya", 500, 40);
  struct openTime t_sukiya = {0, 24};
  sukiya.AddOpenTime(&t_sukiya);
  list.Add(&sukiya);

  Restaurant saboten("saboten", 900, 60);
  struct openTime t_saboten[2] = {{11, 15}, {18, 21}};
  for(int i=0; i<2; ++i)
    saboten.AddOpenTime(t_saboten+i);
  list.Add(&saboten);

  Restaurant ichi("ichi", 900, 60);
  tsuruya.AddClosedWday(Sun);
  struct openTime t_ichi = {0, 24};
  ichi.AddOpenTime(&t_ichi);
  list.Add(&ichi);

  Restaurant manakamana("manakamana", 900, 60);
  struct openTime t_manakamana = {11, 24};
  manakamana.AddOpenTime(&t_manakamana);
  list.Add(&manakamana);

  Restaurant ikoi("ikoi", 1200, 60);
  ikoi.AddClosedWday(Tue);
  struct openTime t_ikoi[2] = { {11.5, 14}, {17.5, 21} };
  for(int i=0; i<2; ++i)
    uoyasu.AddOpenTime(t_ikoi+i);
  list.Add(&ikoi);

  seven.SetWeight(0);
  ikoi.SetWeight(0);

  
  list.Show();
  //list.Random();

  return 0;
}