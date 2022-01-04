protected nomask mixed _query( mapping map, string *parts )
{
	mixed value;
	int i, s,v2;
       mapping result=([ "value": 0;0 ]);
	value = map;
	s = sizeof( parts );
	for( i = 0 ; i < s ; i++ ) {
		v2=member(value,parts[i]);
		if( undefinedp( value = value[parts[i]] ) )
			break;
		if( !mappingp( value ) )
			break;
	}
	result["value", 0]=value;
	result["value", 1]=v2;
	return copy(result);
}

protected nomask int _delete( mapping map, string *parts )
{
	if( sizeof( parts ) == 1 ) {
		map_delete( map, parts[0] );
		return 1;
	}
	if( !map[parts[0]] || !mappingp( map[parts[0]] ) )
		return 0;
	return _delete( map[parts[0]], parts[1..sizeof(parts)-1] );
}

protected nomask mixed _set( mapping map, string *parts, mixed value )
{
	if( sizeof( parts ) == 1 )
		return map[parts[0]] = value;

	if( !map[parts[0]] || !mapp( map[parts[0]] ) )
		map[parts[0]] = ([ parts[1] : 0 ]);

	return _set( map[parts[0]], parts[1..sizeof(parts)-1], value );
}