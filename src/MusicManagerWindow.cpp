/*
 * Copyright 2016-2017 Raefaldhi Amartya Junior <raefaldhiamartya@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#include "MusicManagerWindow.h"

#include <Button.h>
#include <MenuBar.h>
#include <SplitView.h>
#include <StringView.h>
#include <View.h>
#include <LayoutBuilder.h>
#include <GroupLayout.h>
#include <SpaceLayoutItem.h>

#include "Control.h"
#include "Playlist.h"

MusicManagerWindow::MusicManagerWindow()
				  : BWindow(BRect(100, 100, 400, 400), "Music Manager",
				  	B_DOCUMENT_WINDOW, B_QUIT_ON_WINDOW_CLOSE) {
	BView* mmView = new BView("mmView", B_WILL_DRAW);

	BLayoutBuilder::Group<>(mmView, B_VERTICAL)
		.SetInsets(10)		
		.AddGroup(B_HORIZONTAL, B_USE_DEFAULT_SPACING, 2)
			.Add(Playlist::GetPlaylist())
			.Add(Playlist::GetPlaylistContent())
		.End()
		.Add(Control::GetControlBox())
	.End();
	BLayoutBuilder::Group<>(this, B_VERTICAL, 0.0f)
		.SetInsets(0)
		.Add(mmView)
	.End();
}
