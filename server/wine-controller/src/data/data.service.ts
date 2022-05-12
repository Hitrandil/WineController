import { BadRequestException, Injectable } from '@nestjs/common';
import { ConfigService } from '@nestjs/config';
import { PrismaService } from 'src/prisma/prisma.service';
import { LogDto } from './dto';

@Injectable()
export class DataService {
    constructor(private prisma: PrismaService, private config: ConfigService){};
    saveDataOnDB(logESP: LogDto){
        if (logESP.token!=this.config.get("TOKEN_ESP")){
            throw new BadRequestException("Token errato");
        }
        delete logESP.token;
        return this.prisma.log.create({data:logESP});
    }
}
