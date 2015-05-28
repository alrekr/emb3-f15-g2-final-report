STATE = IDLE;
while( True ){
	switch( STATE )
	{
	case IDLE:
		//If the tracker can see the UAS take control
		if( DRONE_IN_RANGE () )
		{
			STATE = GUIDE;
		}
		break;
	case GUIDE:
		face_north();
		while( !within_threshold_x() ) {
			move_towards_center(curr_x);
		}
		while( !within_threshold_y() ) {
			move_towards_center(curr_y);
		}
		STATE = LAND;
		break;
	case LAND:
		while( !connected( ) ){
			descend();
			adjust(curr_x);
			adjust(curr_y);
		}
		STATE = CONNECTED;
		break;
	case CONNECTED:
		disarm();
		return 0;
		break;
	}
}
