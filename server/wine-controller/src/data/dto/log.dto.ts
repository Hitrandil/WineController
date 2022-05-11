import { IsDate, IsNotEmpty, IsNumber, IsString } from "class-validator";

export class LogDto {
    // @IsDate()
    // @IsNotEmpty()
    // timestamp: Date; //todo implementare con orario

    @IsNumber()
    @IsNotEmpty()
    temperature: number;

    @IsNumber()
    @IsNotEmpty()
    humidity: number;

    @IsString()
    @IsNotEmpty()
    hash: string;
}