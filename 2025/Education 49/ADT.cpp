

Vehicle(const Vehicle& other)
{
	vehicleID = new int(*other.vehicleID) ; 
	cout<<
}
Car(const Car&other):Vehicle(other)
{

}


ElectricCar(const ElectricCar& other):Car(other)
{


}
~Vehicle()
{
	delete VehicleID ;
}