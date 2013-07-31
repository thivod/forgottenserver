//////////////////////////////////////////////////////////////////////
// The Forgotten Server - a server application for the MMORPG Tibia
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#ifndef __TRASHHOLDER_H__
#define __TRASHHOLDER_H__

#include "item.h"
#include "cylinder.h"
#include "const.h"

class TrashHolder : public Item, public Cylinder
{
	public:
		TrashHolder(uint16_t _type, MagicEffectClasses _effect = NM_ME_NONE);
		~TrashHolder();

		virtual TrashHolder* getTrashHolder() {
			return this;
		}
		virtual const TrashHolder* getTrashHolder() const {
			return this;
		}

		//cylinder implementations
		virtual ReturnValue queryAdd(int32_t index, const Thing* thing, uint32_t count,
		                               uint32_t flags, Creature* actor = NULL) const;
		virtual ReturnValue queryMaxCount(int32_t index, const Thing* thing, uint32_t count,
		                                    uint32_t& maxQueryCount, uint32_t flags) const;
		virtual ReturnValue queryRemove(const Thing* thing, uint32_t count, uint32_t flags) const;
		virtual Cylinder* queryDestination(int32_t& index, const Thing* thing, Item** destItem,
		                                     uint32_t& flags);

		virtual void addThing(Thing* thing);
		virtual void addThing(int32_t index, Thing* thing);

		virtual void updateThing(Thing* thing, uint16_t itemId, uint32_t count);
		virtual void replaceThing(uint32_t index, Thing* thing);

		virtual void removeThing(Thing* thing, uint32_t count);

		virtual void postAddNotification(Thing* thing, const Cylinder* oldParent, int32_t index, cylinderlink_t link = LINK_OWNER);
		virtual void postRemoveNotification(Thing* thing, const Cylinder* newParent, int32_t index, bool isCompleteRemoval, cylinderlink_t link = LINK_OWNER);

	private:
		MagicEffectClasses effect;
};

#endif
