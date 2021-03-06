#define LOADOUT_WIDTH 			270

#define ORIGIN_LOADOUT			((-(LOADOUT_WIDTH - RIGHTITEM_OFFSET))-80) 38

#define RATEBAR_FRAME_BORDER		0//WINDOW_BORDER_SUNKEN
#define RATEBAR_FRAME_BORDERSIZE	2
#define RATEBAR_FRAME_BORDERCOLOR	0.4 0.4 0.425 1

#define RATEBAR_BAR_SHADER			"gradient_fadein"
#define RATEBAR_BAR_COLOR			1 1 1 0.3

#define RATE_BAR_WIDTH				98
#define RATE_BAR_HEIGHT				12
	
#define VIS_WHEN_ATTACH_PLUS(pweapon,pattribute) visible when( (STAT_CAC_PRIMARY_ATTACHMENT != 0) && (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) > 0) )
#define VIS_WHEN_ATTACH_MINUS(pweapon,pattribute) visible when( (STAT_CAC_PRIMARY_ATTACHMENT != 0) && (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) < 0) ) 

#define VIS_WHEN_ATTACH_PLUS_PREVIEW(pweapon,pattribute,extraArg) visible when( (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) > 0) && extraArg )
#define VIS_WHEN_ATTACH_MINUS_PREVIEW(pweapon,pattribute,extraArg) visible when( (int(tablelookup("mp/attributesTable.csv",1,pweapon,pattribute)) < 0) && extraArg ) 

	#define LOADOUT_ALIGN 	RIGHTITEM_ALIGN VERTICAL_ALIGN_TOP
	#define PERK_ALIGN		
	
	#define LOADOUT_PLATING( py, ph, vis_gradient_top, vis_gradient_bottom ) \
			LOADOUT_PLATING_RAW( ORIGIN_LOADOUT, 0, py, (LOADOUT_WIDTH+8), ph, LOADOUT_ALIGN, vis_gradient_top, vis_gradient_bottom )
		
	// background frame --------
	PREPROC_SHADER_DRAW_ALIGNED( -4 0 (LOADOUT_WIDTH+8) 214 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient_center", 0.3 0.3 0.325 0.6, 0, 0, 0 0 0 0 )


	PREPROC_SHADER_DRAW_ALIGNED( -24 -4 -20 222 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )

	PREPROC_SHADER_DRAW_ALIGNED( (LOADOUT_WIDTH+4) -4 20 222 LOADOUT_ALIGN, ORIGIN_LOADOUT, "gradient", 1 1 1 0.65, 0, 0, 0 0 0 0 )

	// primary weapon camo
	PREPROC_SHADER_DRAW_ALIGNED( -4 4 ((LOADOUT_WIDTH+8)/4) 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
	PREPROC_SHADER_DRAW_ALIGNED( (((LOADOUT_WIDTH+8)/4)-4) 4 ((LOADOUT_WIDTH+8)/4) 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
	PREPROC_SHADER_DRAW_ALIGNED( (((LOADOUT_WIDTH+8)/2)-4) 4 ((LOADOUT_WIDTH+8)/4) 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 
	PREPROC_SHADER_DRAW_ALIGNED( ((((LOADOUT_WIDTH+8)/4)*3)-4) 4 ((LOADOUT_WIDTH+8)/4) 80 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 11, STAT_CAC_CAMO, 6 ), 1 1 1 0.5, 0, 1, 1 1 1 1) 

	/* top bar */ 			LOADOUT_PLATING( 4, 8, 0, 1 )
	/* bottom bar */		LOADOUT_PLATING( 218, 8, 1, 0 )
	/* weapon divider */ 	LOADOUT_PLATING( 92, 8, 1, 1 )
	/* perk plate */ 		LOADOUT_PLATING( 180, 8, 1, 1 )

// weapon loadout info display ============
	
	// primary weapon name
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 8 (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/statstable.csv", 0, STAT_CAC_PRIMARY, 3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	// primary weapon attachment name
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 62 (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/attachmenttable.csv", 9, STAT_CAC_PRIMARY_ATTACHMENT, 3), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )
	// primary weapon image
	PREPROC_SHADER_DRAW_ALIGNED( 74 -2 180 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 0, STAT_CAC_PRIMARY, 6 ), 1 1 1 1, 0, 1, 1 1 1 1) 
	// primary weapon attachment image
	PREPROC_SHADER_DRAW_ALIGNED( 2 30 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 9, STAT_CAC_PRIMARY_ATTACHMENT, 6 ), 1 1 1 1, 0, 1, 1 1 1 1) 	
	
	// second weapon name
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 (8+88) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@" + tablelookup("mp/statstable.csv", 0, STAT_CAC_SECONDARY, 3), TEXTSIZE_DEFAULT, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE )
	// second weapon attachment name
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 (62+88) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "@"+tablelookup("mp/attachmenttable.csv", 9, STAT_CAC_SECONDARY_ATTACHMENT, 3), TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, CHOICE_TEXTCOLOR )
	// second weapon image
	PREPROC_SHADER_DRAW_ALIGNED( 160 (6+80) 90 90 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/statstable.csv", 0, STAT_CAC_SECONDARY, 6 ), 1 1 1 1, 0, 1, 1 1 1 1) 
	// second weapon attachment image
	PREPROC_SHADER_DRAW_ALIGNED( 2 118 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, tablelookup( "mp/attachmenttable.csv", 9, STAT_CAC_SECONDARY_ATTACHMENT, 6 ), 1 1 1 1, 0, 1, 1 1 1 1) 	

	
	#define PERK_Y_OFFSET	183
	#define PERK_Y_SPACING	0

  // grenade name -------------
	#define LOCAL_GRENADE( ptext, visArg ) \
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 36 (PERK_Y_OFFSET+(PERK_Y_SPACING*3)) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, \
	ORIGIN_LOADOUT, ptext, TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE visible when( visArg ); )

	// grenade icons ------------
	PREPROC_SHADER_DRAW_ALIGNED( 3 (PERK_Y_OFFSET-5+(PERK_Y_SPACING*3)) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, "weapon_fraggrenade", 1 1 1 1, 0, 1, 1 1 1 1 visible when( 1 ) ) 
	PREPROC_SHADER_DRAW_ALIGNED( 32 (PERK_Y_OFFSET-5+(PERK_Y_SPACING*3)) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, "weapon_smokegrenade", 1 1 1 1, 0, 1, 1 1 1 1 visible when( dvarString( loadout_grenade ) != "flash_grenade" ) ) 
	PREPROC_SHADER_DRAW_ALIGNED( 32 (PERK_Y_OFFSET-5+(PERK_Y_SPACING*3)) 32 32 LOADOUT_ALIGN, ORIGIN_LOADOUT, "weapon_flashbang", 1 1 1 1, 0, 1, 1 1 1 1 visible when( dvarString( loadout_grenade ) == "flash_grenade" ) )

	// grenade counts ------------
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 (PERK_Y_OFFSET+(PERK_Y_SPACING*3)) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "1", TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE visible when(dvarint(weap_allow_frag_grenade) == 1); )
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 0 (PERK_Y_OFFSET+(PERK_Y_SPACING*3)) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "0", TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE visible when(dvarint(weap_allow_frag_grenade) == 0); )

	PREPROC_TEXT_DRAW_ALIGNED_EXP( 30 (PERK_Y_OFFSET+(PERK_Y_SPACING*3)) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "1", TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE visible when( (dvarString( loadout_grenade ) == "flash_grenade" && dvarInt( weap_allow_flash_grenade ) == 1 ) || (dvarString( loadout_grenade ) == "smoke_grenade" && dvarInt( weap_allow_smoke_grenade ) == 1 ) ); )
	PREPROC_TEXT_DRAW_ALIGNED_EXP( 30 (PERK_Y_OFFSET+(PERK_Y_SPACING*3)) (LOADOUT_WIDTH+8) 20 LOADOUT_ALIGN, ORIGIN_LOADOUT, "0", TEXTSIZE_SMALL, 0, 0, ITEM_ALIGN_MIDDLE_LEFT, COLOR_TITLE visible when( dvarstring( loadout_grenade ) != "flash_grenade" && dvarstring( loadout_grenade ) != "smoke_grenade" ); )